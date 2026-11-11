#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],c[500005],n,r,maxx,Q,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=(a[i]-a[i-1])+c[i-1];
	}
	l=1;
	while(r<=n){
		r++;
		while(1){
			Q+=(c[r]-c[r-1])*(r-l);
			if(Q>m){
				l++;
				Q-=(c[r]-a[l-1]);
			}else{
				break;
			}
		}
		maxx=max(maxx,(r-l+1));
	}
	cout<<min(maxx,n);
	return 0;
}
