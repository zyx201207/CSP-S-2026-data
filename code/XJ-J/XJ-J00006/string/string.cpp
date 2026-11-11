#include<bits/stdc++.h>
using namespace std;
int n,s;
char c[1000001000];
long long a[1000001000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)if(c[i]==c[i+1])s++;
	if(s==n)cout<<0;
	return 0;
}