#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int v[300010];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(s.find(char(a[j] + '0')) != s.npos){
				int op = s.find(char(a[j] + '0'));
				s.erase(op, s.length() - op);
			}
			s += char(a[j] + '0');
		}
		for(int i = 0;i < s.length();i++){
			int x = int(s[i] - '0');
			v[x]++;
		}
		s.clear();
	}
	for(int i = 1;i <= m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
