#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
long long b[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=0,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int cnt=1;
		for(int i=1;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
	}
	if(m==n-1){
		int tnt=1,p=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++){
				p=a[i]&a[j];
				tnt=max(tnt,p);
			}
		}
		cout<<tnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==3){
			t=max(a[i],b[i]);
			cout<<t;
		}
		a[i]=b[i];
	}
	return 0;
}
