#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto MaxNum = int{ 20'0002 };

vi root{};
vi countNet{};

int nextId;
map<string, int> fid{};

string a, b;

int par(int x) {
	if (x == root[x]) {
		return x;
	}

	return root[x] = par(root[x]);
}

void merge(int x, int y) {
	x = par(x);
	y = par(y);

	if (x == y) {
		return;
	}

	if (countNet[x] < countNet[y]) {
		swap(x, y);
	}

	countNet[x] += countNet[y];
	root[y] = x;
}

void update() {
	if (fid.end() == fid.find(a)) {
		fid[a] = nextId;
		++nextId;
	}

	if (fid.end() == fid.find(b)) {
		fid[b] = nextId;
		++nextId;
	}

	merge(fid[a], fid[b]);

	const auto ar = par(fid[a]);
	const auto br = par(fid[b]);

	cout << max(countNet[ar], countNet[br]) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		countNet = vi(MaxNum, 1);
		root = vi(MaxNum, 1);
		for (auto i = 0; i < MaxNum; ++i) {
			root[i] = i;
		}

		nextId = 1;
		fid = map<string, int>{};

		int f;
		cin >> f;
		while (0 < (f--)) {
			cin >> a >> b;

			update();
		}
	}

	return 0;
}