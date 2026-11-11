#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[100005],ma=-1e18,mi=1e18,cnt[100005],ans=0;
bool dfs(long long oo,long long x){
	long long h=cnt[x],g[100005],w=m,k=0,ans=0;
	for(int i=1;i<=h;i++){
		g[i]=oo-a[i];
	}
	for(int i=h;i>=1;i--){
		if(k+g[i]>=w){
			break;
		}
		else{
			k+=g[i];
			ans++;
		}
	}
	if(ans>=x)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=mi;i<=ma;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				cnt[i]++;
			}
			else{
				break;
			}
		}
		//cout<<cnt[i]<<endl;
	}
	for(int i=1;i<=ma;i++){
		long long l=1,r=cnt[i],mid;
		while(l<=r){
			mid=(l+r)/2;
			if(dfs(i,mid)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}

/*
5 5
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/
