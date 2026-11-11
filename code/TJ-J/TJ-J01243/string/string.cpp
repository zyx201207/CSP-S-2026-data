#include <bits/stdc++.h>
using namespace std;
int n,r=1,cnt,sum;
string a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--)
	{
		int num;
		string w;
		for(int i = r;i <= r + num;i++)
		{
			if(a[i] == a[i-1]) sum++;
			a[i] = w;
		}
		r += num;
	}
	if(sum >= n)
	{
		cout << 0;
		return 0;
	}
	int l = 1,m = (l+r-1)/2;
	for(int i = 1;i <= m;i++)
	{
		if(a[r-1] != a[l-1])
		{
			a[r-1] = a[l-1];
			l++,r--;
			cnt++;
		}
	}
	cout << cnt-1;
	return 0;
} 
