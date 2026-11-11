#include<bits/stdc++.h>
using namespace std;
const int N=3000,M=5000;
int n,m;
int t[N],a[M],vis[N],s[M];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			t[j]=0,vis[j]=0,s[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				x++;
				s[x]=a[j];
				t[a[j]]=x;
			}
			else {
				x=t[a[j]];
			}
		}
		for(int k=1;k<=x&&k<=n;k++){
			if(vis[s[k]]==0){
				ans[s[k]]++;
				vis[s[k]]=1;
			}
			cout<<s[k]<<" ";
		}cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}//10 3 3 1 2 1 3 2 3 1 2 1