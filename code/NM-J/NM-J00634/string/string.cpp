#include<bits/stdc++.h>
using namespace std;
long long o,m = 1;
int a[200010],n;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		for(int j = m;j <= m+a[i];j++)
			s[j] = c[i];
		m += a[i];
	}
	if(m % 2 == 0)
		for(long long i = 1;i <= m/2;i++){
			if(s[i] != s[m - i + 1])
				o++;
		}
		
	else
	    for(long long i = 1;i < (m/2)+1;i++)
			if(s[i] != s[m - i + 1])
				o++;
	cout<<o;

	return 0;
}
