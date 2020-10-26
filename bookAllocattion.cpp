//
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool check(vector<int> v, int cur_min, int s)
{


	int studentUsed = 1;
	int pages_reading = 0;
	for (int i = 0; i < v.size(); i++) {
		if (pages_reading + v[i] > cur_min) {
			studentUsed++;

			pages_reading = v[i];
			if (studentUsed > s)
				return false;
		}
		else {
			pages_reading += v[i];
		}

	}
	return true;


}
int func(vector<int> v, int s)
{
	int low = v[v.size() - 1];
	int high = accumulate(v.begin(), v.end(), 0);
	//cout << high << endl;
	int ans = INT_MAX;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		//cout << "mid=" << mid << endl;
		bool c = check(v, mid, s);
		//	cout << "c=" << c << endl;
		if (c)
		{
			ans = min(ans, mid);
			high = mid - 1 ;
		}
		else low = mid + 1;
	}

	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, s;
		cin >> n >> s;
		int a;
		std::vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v.pb(a);
		}
		cout << func(v, s) << endl;
	}
	return 0;
}