#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],vst[5005][5005],vstc[5005][5005],miinc,miind;
int dfs(int i,int j,int sum){
	if(sum>miind){
		return 1e7;
	}
	if(i==j){
		if(sum<miind){
			miinc=1,miind=sum;
		}else if(sum==miind){
			miinc++;
		}
		return sum;
	}
	if(i+1==j&&a[j]-a[i]<=d){
		if(sum+1<miind){
			miinc=1,miind=sum+1;
		}else if(sum+1==miind){
			miinc++;
		}
		return sum+1;
	}
	int miin=1e9;
	for(int k=i+1;k<=j;k++){
		if(a[k]-a[i]<=d){
			miin=min(miin,dfs(k,j,sum+1));
		}
		else break;
	}
	vst[i][j]=miin;
	return miin+sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				miinc=0,miind=1e9;
				dfs(i,j,0);
				if(miinc==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
