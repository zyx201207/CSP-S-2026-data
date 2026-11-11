#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
LL s[N], len;
char c[N];
struct Node
{
	LL l, r;
	char val;
};
vector<Node> l, r;

LL solve()
{
	int cntl = 0, cntr = r.size() - 1; // 保证 l 一样 
	LL res = 0;
	while(1)
	{
		//  puts("-----------");
		if(l[cntl].r > r[cntr].r)
		{
			if(l[cntl].val != r[cntr].val) res += r[cntr].r - r[cntr].l + 1;
			l[cntl] = {r[cntr].r + 1, l[cntl].r, l[cntl].val};
			cntr --;
		}
		else if(l[cntl].r < r[cntr].r)
		{
			if(l[cntl].val != r[cntr].val) res += l[cntl].r - l[cntl].l + 1;
			r[cntr] = {l[cntl].r + 1, r[cntr].r, r[cntr].val};
			cntl ++;
		}
		else
		{
			if(l[cntl].val != r[cntr].val) res += l[cntl].r - l[cntl].l + 1;
			cntl ++, cntr --;
		}
		if(cntl >= l.size() && cntr < 0) return res;
	}
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld %c", &s[i], &c[i]);
		s[i] += s[i - 1];
	}
	len = s[n];
	// cout << "len: " << len << endl;
	// mid - 1: len / 2    mid + 1: (len - 1) / 2 + 2
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] <= len / 2) l.push_back({s[i - 1] + 1, s[i], c[i]});
		else if(s[i - 1] + 1 >= (len - 1) / 2 + 2)
			r.push_back({len - s[i] + 1, len - (s[i - 1] + 1) + 1, c[i]});
		else
		{
			if(s[i - 1] + 1 <= len / 2) l.push_back({s[i - 1] + 1, len / 2, c[i]});
			if((len - 1) / 2 + 2 <= s[i]) r.push_back({len - s[i] + 1, len - ((len - 1) / 2 + 2) + 1, c[i]});
		}
	}
	/*
	puts("---------------------------------");
	for(int i = 0; i < l.size(); i ++)
		cout << "l: " << l[i].l << ", r: " << l[i].r << ", val: " << l[i].val << endl;
	puts("----------------------------------");
	for(int i = 0; i < r.size(); i ++)
		cout << "l: " << r[i].l << ", r: " << r[i].r << ", val: " << r[i].val << endl;
	puts("----------------------------------");
	*/
	cout << solve() << endl;;
	return 0;
}
