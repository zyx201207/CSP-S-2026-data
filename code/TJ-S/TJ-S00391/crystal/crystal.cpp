#include<bits/stdc++.h>
using namespace std;
const int N=5e3+8,M=2e5+8,diff=1e5;
int n,m,a[N],cnt[M],dif[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]+diff]++;
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dif[j]=a[i]-a[j];
		} 
		sort(dif+1,dif+i);
		int rmn=m,res=cnt[a[i]+diff];
		for(int j=1;j<i;j++){
			if(a[i]==a[j])continue;
			if(rmn<dif[j]){
				ans=max(ans,res);
				break;
			}
			rmn-=dif[j];
			res++;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
