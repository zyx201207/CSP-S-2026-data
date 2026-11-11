#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
int ans[5005];
int t[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			int l=-1,r=-1;
			t[j]=a[j];
			for(int k=j;k>=i;k--){
				if(t[k]==-1) continue;
				if(t[j]==t[k]){
					l=k+1;
					r=j;
				}
			}
			if(l==-1) continue;
			else{
				for(int k=l;k<=r;k++){
					t[k]=-1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(t[j]==-1) continue;
			else ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	//bjy
}
