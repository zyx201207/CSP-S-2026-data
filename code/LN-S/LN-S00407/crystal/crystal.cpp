#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx,s,p=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=0;
	for(int i=a[1];;i++){
		if(i!=a[1])s+=p;
		if(i==a[p+1])p++;
		if(s>m){cout<<p-1;break;}
		else if(s==m){cout<<p;break;}
	}
	return 0;
}
