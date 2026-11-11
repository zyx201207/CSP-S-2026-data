#include<bits/stdc++.h>
using namespace std;
int m,n,a[200003],ans,vis[200003];
int s[200005][34];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int w=a[i],cnt=0;
		while(w){
			s[i][++cnt]=(w%2);
			w/=2;
			//~ cout<<s[i][cnt]<<" ";
		}
		//~ cout<<endl;
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			sum+=s[j][i];
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(!s[j][i]){
					vis[j]=1;
				}
			}
			ans+=(1<<(i-1));
			//~ cout<<i<<endl;
		}
	}
	cout<<ans;
	return 0;
}
