#include <bits/stdc++.h>
using namespace std;
char a[200005];
int cnt;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin>>n;
	int t=1;
	for(int i=1;i<=n;i++){
		int x;
		char s;
		cin>>x>>s;
		for(int j=1;j<=x;j++){
			a[t++]=s;
		}
	}
	for(int i=1;i<=t/2;i++){
		if(a[i]!=a[t-i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}