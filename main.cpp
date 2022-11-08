#include <climits>
#include <iostream>

using namespace std;

int best[400005];
int indbest[400005];

int product;

void process(int sum, int num) {
	int ind = product - sum + num;
	if (best[ind]>product)
		best[ind] = product;
}

void generate(int n, int k, int s, int num) {
	for (int k2 = k*k; k2 <= n; ++k, k2 = k*k) {
		if (!(n%k)) {
			int quotient = n / k;
			process(s + k + quotient, num + 2);
			if (k2 <= quotient)
				generate(quotient, k, s + k, num + 1);
		}
	}
}

int main() {
	int n = 12000;

	const int maxval = 2 * n;

	for (int i = 0; i <= maxval; ++i)
		best[i] = INT_MAX;
	for (product = 4; product <= maxval; ++product)
		generate(product, 2, 0, 0);
	int sum = 0;
	for (int i = 2; i <= n; ++i) {
		int bi = best[i];
		if (!indbest[bi]) {
			indbest[bi] = 1;
			sum += bi;
		}
	}

	cout << sum << endl;

	return 0;
}
