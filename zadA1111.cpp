//Zuzanna Poznańska

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class para {

int num;
string word;
int *sort;

public:

	para () {}
	para(int n, string w) {
		num = n;
		word = w;
		sort = new int[word.length()];
		char *str = new char[word.length()];
		for (int i = 0; i < word.length(); i++) {
			str[i] = word[i];
			sort[i] = int(str[i]);
		}
		delete[] str;
	}

	void print() {
		cout << num << " " << word << " ";
	}

	void set_num(int x) {
		this->num = x;
	}

	void set_word(string w) {
		this->word = w;
		char *str = new char[word.length()];
		for (int i = 0; i < word.length(); i++) {
			str[i] = word[i];
			this->sort[i] = int(str[i]);
		}
		delete[] str;
	}

	int get_int() {
		return num;
	}

	string get_string() {
		return word;
	}

	void set_para(para y) {
		this->num = y.get_int();
		this->word = y.get_string();
		char *str = new char[this->word.length()];
		for (int i = 0; i < this->word.length(); i++) {
			str[i] = this->word[i];
			this->sort[i] = int(str[i]);
		}
		delete[] str;

	}

	int get_letter(int x) {
		return sort[x];
	}

	~para() {
		delete[] sort;
	}

};

void swap(int &a, int &b, para &x, para &y) {
	int tmp = a;
	a = b;
	b = tmp;

	para t(0," ");
	t.set_para(x);
	x.set_para(y);
	y.set_para(t);
}

int partitionrosn(int arr[], int start, int end,vector<para>& p) {

	int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start],p[pivotIndex],p[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--],p[i++],p[j--]);
        }
    }

    return pivotIndex;
}

int partitionmal(int arr[], int start, int end, vector<para>& p) {

	int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start],p[pivotIndex],p[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] >= pivot) {
            i++;
        }

        while (arr[j] < pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--],p[i++],p[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end, int x, vector<para>& p)
{

    if (start >= end)
        return;

    int s;
    if (x == 0) s = partitionrosn(arr, start, end,p);
    else s = partitionmal(arr, start, end,p);

    quickSort(arr, start, s - 1,x,p);

    quickSort(arr, s + 1, end,x,p);
}

void sort_string(int N, vector<para>& p) {
	int min = 10000;

	for (int i = 0; i < N; i++)	{
		if(p[i].get_string().length() < min) min = p[i].get_string().length();
	}

	
	int count = 0;
	int j = 1;
	while(j < min) {	
		for(int i = 0; i <  N - 1; i++) {

			if(p[i].get_letter(j-1) == p[i+1].get_letter(j-1) ) count++;
			if(p[i].get_letter(j-1) != p[i+1].get_letter(j-1) && count != 0) {//
				
				int *next = new int[count];
				vector<para> temp;
                                    				
				for(int k = 0; k < count; k++) {

					next[k] = p[i-count+k].get_letter(j);
					temp.push_back(p[i-count+k]);

				}

				quickSort(next,0,count,0,temp);

				for(int k = 0; k < count; k++) {
					p[i-count+k].set_para(temp[k]);	
			}

				count = 0;
				delete []next;
			}
		}
		j++;
	}
}



void sort_rosn(int N, vector<para>& p) {

	int tab[N];

	for (int i = 0; i < N; i++)	{
		tab[i] = p[i].get_int();
	}
	cout << "przed quickSort" << endl;

	quickSort(tab,0,N-1,0,p);

	cout << "po quickSort" << endl;

	int count = 0;
		
	for(int i = 0; i < N - 1; i++) {
		if(tab[i] == tab[i+1]) count++;
		if(tab[i] != tab[i+1] && count!= 0) {//
			
			int *next = new int[count];
			vector<para> temp;
			
			for(int k = 0; k < count; k++) {

				next[k] = p[i-count+k].get_letter(0);//
				temp.push_back(p[i-count+k]);

			}

			quickSort(next,0,count,0,temp);

			for(int k = 0; k < count; k++) {
				
				p[i-count+k].set_para(temp[k]);

			}

			count = 0;
			delete []next;
		}
	}

	//sort_string(N,p);

}

void sort_mal(int N, vector<para>& p) {

	int tab[N];

	for (int i = 0; i < N; i++)	{
		tab[i] = p[i].get_int();
	}

	quickSort(tab,0,N-1,3,p);

	int count = 0;
		
	for(int i = 0; i < N - 1; i++) {
		if(tab[i] == tab[i+1]) count++;
		if(tab[i] != tab[i+1] && count!= 0) {//
			
			int *next = new int[count];
			vector<para> temp;
			
			for(int k = 0; k < count; k++) {

				next[k] = p[i-count+k].get_letter(0);//
				temp.push_back(p[i-count+k]);

			}

			quickSort(next,0,count,0,temp);

			for(int k = 0; k < count; k++) {
				
				p[i-count+k].set_para(temp[k]);

			}

			count = 0;
			delete []next;
		}
	}

	sort_string(N,p);

}



int main() {

	int M;

	cin >> M;

	for(int i = 0; i < M; i++) {

		char c;

		cin >> c;

		int N;
		cin >> N;
		
		vector<para> p;


		for(int j = 0; j < N; j++) {
			int n;
			string w;
			cin >> n;
			cin >> w;

			p.push_back(para(n,w));
		}

		if(int(c) == 60) {

			sort_rosn(N,p);
			for (int i = 0; i < N; i++)	{
				p[i].print();
			}
		}

		else if(int(c) == 62) {

			sort_mal(N,p);
			for (int i = 0; i < N; i++)	{
				p[i].print();
			}
		}

	}
}