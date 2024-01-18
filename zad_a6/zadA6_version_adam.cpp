#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <utility>

using namespace std;

class Pixel {
public:
    bool isBad, visited;
    int x, y;
    Pixel* up;
    Pixel* down;
    Pixel* left;
    Pixel* right;

    Pixel(int x, int y) : x(x), y(y), isBad(false), visited(false), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};

void dfsIterative(Pixel* start, pair<int, int>& minPixel) {
    stack<Pixel*> stack;
    stack.push(start);

    while (!stack.empty()) {
        Pixel* pixel = stack.top();
        stack.pop();

        if (!pixel || pixel->visited || !pixel->isBad) continue;

        pixel->visited = true;
        minPixel = min(minPixel, make_pair(pixel->y, pixel->x));

        stack.push(pixel->up);
        stack.push(pixel->down);
        stack.push(pixel->left);
        stack.push(pixel->right);
    }
}

int main() {
    int set;
    cin >> set;
    while (set--) {
        int height_matrix, width_matrix, bad_pixels;
        cin >> height_matrix >> width_matrix >> bad_pixels;

        vector<vector<Pixel>> grid(height_matrix, vector<Pixel>(width_matrix, Pixel(0, 0)));
        for (int y = 0; y < height_matrix; ++y) {
            for (int x = 0; x < width_matrix; ++x) {
                grid[y][x] = Pixel(x, y);
                if (y > 0) grid[y][x].up = &grid[y-1][x];
                if (y < height_matrix - 1) grid[y][x].down = &grid[y+1][x];
                if (x > 0) grid[y][x].left = &grid[y][x-1];
                if (x < width_matrix - 1) grid[y][x].right = &grid[y][x+1];
            }
        }

        for (int i = 0; i < bad_pixels; ++i) {
            int x, y;
            cin >> x >> y;
            grid[y][x].isBad = true;
        }

        int count = 0;
        vector<pair<int, int>> representatives;
        for (int y = 0; y < height_matrix; ++y) {
            for (int x = 0; x < width_matrix; ++x) {
                if (grid[y][x].isBad && !grid[y][x].visited) {
                    pair<int, int> minPixel = make_pair(INT_MAX, INT_MAX);
                    dfsIterative(&grid[y][x], minPixel);
                    representatives.push_back(minPixel);
                    count++;
                }
            }
        }
        
        cout << count << endl;
        for (auto& rep : representatives) {
            cout << rep.second << " " << rep.first << endl;
        }
    }
    return 0;
}
