#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll need,able;
} no[500005];
ll n,m,a[500005],ans,tmp;
bool isB=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(size_t i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)tmp=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=tmp)isB=false;
	}
	sort(a+1,a+n+1);
	if(isB){
		for(size_t i=1;i<=n;i++){//base
			no[i].need=no[i-1].need+(a[i]-a[i-1])*(i-1);
			no[i].able=i;
			if(m<no[i].need){
				cout<<no[i-1].able;
				return 0;
			}
		}
	}
	for(size_t i=1;i<=n;i++){//base
		no[i-1].need=0;no[i-1].able=0;
		for(size_t j=i;j<=n;j++){
			no[j].need=no[j-1].need+(a[j]-a[j-1])*(j-i);
			no[j].able=no[j-1].able+1;
			if(m<no[j].need){
				ans=max(ans,no[j-1].able);
				break;
			}
			else if(j==n) ans=max(ans,no[j].able);
		}
	}
	cout<<ans;
	return 0;
}
