//Zuzanna Poznańska

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class person {

	int prestige;
	string name;

  public:
	person() {}

	person(int p, string n) {
		prestige = p;
		name = n;
	}

	int get_prestige() {
		return this->prestige;
	}

	string get_name() {
		return this->name;
	}

	void set_prestige(int p) {
		this->prestige = p;
	}

	void set_name(string n) {
		this->name = n;
	}

	int get_letter(int x) {
		char *str = new char[name.length()];
		for (int i = 0; i < name.length(); i++) {
			str[i] = name[i];
		}
		int y = int(str[x]);
		return y;
	}

	void set_person(person p) {
		this->prestige = p.get_prestige();
		this->name = p.get_name();
	}

	~person() {}
	
};

void swap(person &p, person &s) {
	person tmp = person(p.get_prestige(),p.get_name());
	p.set_person(s);
	s.set_person(tmp);
}

int main() {

	long int z = 1000000;
	person *heap = new person[z];
	for(int i = 0; i < z; i++) heap[i].set_person(person(0,""));
	int maxSize = 0;
	int M;
	cin >> M;

	for(int i = 0; i < M; i++) {
		int N;
		cin >> N;

		for(int j = 0; j < N; j++) {
			int p;
			string n;

			cin >> p;
			cin >> n;

			heap[maxSize].set_person(person(p,n));
			int currpos = maxSize;
			int parent = (maxSize-1)/2;

			person tmp = person(heap[currpos].get_prestige(),heap[currpos].get_name());

			while(currpos > 0 && heap[parent].get_prestige() > tmp.get_prestige()) {
				heap[currpos].set_person(heap[parent]);
				currpos = parent;
				parent = (currpos-1)/2;
			}
			heap[currpos].set_person(tmp);
			maxSize++;
		}
	}

	int currpos = 0;
	int left = 2*currpos;
	int right = 2*currpos + 1;

	person p = person(heap[currpos].get_prestige(),heap[currpos].get_name());
	person l = person(heap[left].get_prestige(),heap[left].get_name());
	person r = person(heap[right].get_prestige(),heap[right].get_name());
	person *tab = new person[z+5];

	while(p.get_name() != "" || !(maxSize == z)) {
		if(p.get_name() != "") {
			if(r.get_name() != "") {
				maxSize--;
				tab[maxSize].set_person(r);
			}
			maxSize--;
			tab[maxSize].set_person(p);
			p.set_person(l);
		}

		else {
			maxSize++;
			p.set_person(tab[maxSize-1]);

			if(r.get_name() != "" && tab[maxSize].get_name() == r.get_name()) {
				tab[maxSize].set_person(p);
				p.set_person(r);
			}
			else {
				cout << " " << p.get_name();
				p.set_person(person(0,""));
			}
		}
	}
	/*while(maxSize != 0) {
		cout << heap[0].get_name();

		heap[0].set_person(heap[maxSize]);
		maxSize--;

		int j = maxSize;
		person tmp = person(heap[j].get_prestige(),heap[j].get_name());
		while(j < maxSize) {
			if(j+1 < maxSize && heap[j+1].get_prestige() < heap[j].get_prestige()) j++; //< ? >
			heap[j].set_person(heap[j+1]);
			j = 2*j+1;
		}
		heap[j+1].set_person(tmp);
	}*/



	delete []heap;

}
