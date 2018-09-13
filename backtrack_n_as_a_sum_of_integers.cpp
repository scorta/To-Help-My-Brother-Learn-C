#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int n, sum;

void print_result() {
	for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
		if (*it) cout << *it << " ";
	}
	cout << endl;
}

void work(const int& i) {
	int k = i == 0 ? 1 : arr[i - 1] > 0 ? arr[i - 1] : 1;
	
	for (int j = k; j < n; ++j) {
		if (sum + j <= n) {
			arr[i] = j;
			sum += j;
			if (sum == n) {
				print_result();
			} else {
				work(i + 1);
			}
			arr[i] = 0;
			sum -= j;
		} else {
			break;
		}
	}
}

int main() {
	cout << "Start!\nN = ?\n";
	cin >> n;
	arr = vector<int>(n);
	sum = 0;
	work(0);

	return 0;
}
