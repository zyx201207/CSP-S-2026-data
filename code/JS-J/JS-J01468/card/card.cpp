#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long vis[300005];
long long behind[500005];
long long ans[500005];
long long delta[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]]!=0){
			behind[i]=vis[a[i]];
		}
		vis[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		delta[a[i]]++;
		if(behind[i]==0){
			for(int j=1;j<=m;j++){
				if(delta[j]>0)ans[j]+=1;
			}
		}
		else{
			for(int j=i+1;j<behind[i];j++){
				delta[a[j]]--;
			}
			for(int j=1;j<=m;j++)if(delta[j]>0)ans[j]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}	
	return 0;
	
}
