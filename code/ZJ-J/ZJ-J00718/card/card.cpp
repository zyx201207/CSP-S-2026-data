#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=3e5+10;
ll n,m,a[N],ans[M];
bool pai=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i-1]>a[i])
			pai=0;
	}
	if(pai==1){//特判 1：特殊性质 A
		for(ll i=2;i<=n;i++)
			if(a[i-1]==a[i])
				a[i-1]=0;
		for(ll i=n;i>=1;i--)
			if(a[i]!=0)
				ans[a[i]]++;
			else
				break;
		for(ll i=1;i<=m;i++)
			cout<<ans[i]<<' ';
	}
	return 0;
}
