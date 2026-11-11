#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],d[500001],anss,s[500001];
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[i]-a[i-1]){
				f=0;
			}		
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	if(f){
		for(long long i=1;i<=n;i++){
			if(i*(i-1)*(a[1]-a[0])>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(long long l=1;l<=n;l++){
		long long r;
		for(r=l;r<=n;r++){
			s[r]=d[r]*(r-l)+s[r-1];
			s[r-1]=0;
			if(s[r]>m){
				s[r]=0;
				break;
			}
		}
		anss=max(anss,r-l);
	}
	cout<<anss;
	return 0;
}
