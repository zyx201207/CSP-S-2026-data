#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,lft=1,rgt=500000,mid=250000,ans=1,st=1;
long long m;
long long a[500005],ad[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ad[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
    }
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		ad[i]=ad[i-1]+a[i];
	}
    a[n+1]=1000000000000000000;
    ad[n+1]=ad[n]+a[n+1];
	while(st<=n){
		lft=st;
		rgt=n+1;
		while(rgt-lft>1){
			mid=(rgt+lft)/2;
			if(a[mid]*(mid-st+1)-ad[mid]+ad[st-1]<=m){
				lft=mid;
			}
			else{
				rgt=mid;
			}
		}
		ans=max(ans,lft-st+1);
		st+=1;
	}
	cout<<ans;
}
