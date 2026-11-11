#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000005],aa,s,maxa=1,maxm=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=maxm;i--){
		aa=m;
		maxa=1;
		s=1;
		while(aa>=a[i]-a[i-s]&&i>s){
			aa=aa-a[i]+a[i-s];
			s=s+1;
			maxa=maxa+1;
		}
		if(maxa>maxm){
			maxm=maxa;
		}
	}
	cout<<maxm;
	return 0;
} 