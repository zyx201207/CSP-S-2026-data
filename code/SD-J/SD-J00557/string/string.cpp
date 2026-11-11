#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
const int L = 1e8+5;
int a[N];
char s[L];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	
	int l = 1;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		
		for(int j = l; j < l+a; j++)
			s[j] = c;
		l += a;
	} l--;
	
	int cnt = 0;
	for(int i=1,j=l; i <= l/2; i++,j--)
	{
		if(s[i] != s[j])
			cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
