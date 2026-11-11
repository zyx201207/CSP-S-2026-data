//郭昕宇 西安市铁一中学 SN-J00713 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],cnt[500005],b[500005],c[500005],ans[500005],mp[500005],nxt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[b[a[i]]]=i;
		b[a[i]]=i;
		c[i]=cnt[a[i]];
	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=4;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	int k=0;
	for(int l=1;l<=n;l++){
		k++;
		for(int i=l;i<=n;i++){
			mp[a[i]]=k;
			if(nxt[i]!=0){
				i=nxt[i]-1;
			}
			
		}
		for(int i=1;i<=m;i++){
			if(mp[i]==k){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
