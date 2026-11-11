#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],pre[500010];
int bts(int x){
	int l=1,r=x,mid,ans=x;
	while(l<=r){
		mid=(l+r)/2;
		if((x-mid+1)*a[x]-(pre[x]-pre[mid-1])>m){
			l=mid+1;
		}else{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}
signed main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	int tmp=a[1];
	for(int i=1;i<=n;i++){
		if(tmp<0)a[i]-=tmp;
		pre[i]=a[i]+pre[i-1];
	}
	for(int i=1;i<=n;i++){
		int mid=bts(i),x=i;
		ans=max(ans,i-bts(i)+1);
	}
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

