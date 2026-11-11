#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	int wt=a[(n+1)/2];
	int ww=n-(n+1)/2;
	int tt=wt-1;
	int ans=0;
	for(int i=1;i<=max(ww,tt);i++){
		m-=2*i;
		ans+=2;
		if(i>ww) ans--,m+=i;
		if(i>tt) ans--,m+=i;
	}
	cout<<ans;
	return 0;
}
