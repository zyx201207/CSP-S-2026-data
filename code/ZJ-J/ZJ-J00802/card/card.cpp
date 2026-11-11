#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,N1=2e5+5;
long long n,m,a[N],ans[N];
struct node{
	int id;
	bool f;
}vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000&&m==2){
		int l1=0,l2=0;
		for(int i=n;i>=1;i--){
			if(a[i]==1){
				l1=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]==2){
				l2=i;
				break;
			}
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans1++;
				if(l1<l2) ans2++;
			}
			else{
				ans2++;
				if(l1>l2) ans1++;
			}
		}
		cout<<ans1<<" "<<ans2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]].f==0){
				vis[a[j]].f=1;
				vis[a[j]].id=j;
			}
			else{
				for(int k=1;k<=m;k++){
					if(vis[k].id>vis[a[j]].id){
						vis[k].id=0;
						vis[k].f=0;
					}
				}
				vis[a[j]].f=1;
				vis[a[j]].id=j;
			}
		}
		for(int j=1;j<=m;j++) ans[j]+=vis[j].f;
		for(int k=1;k<=m;k++) vis[k].f=vis[k].id=0;
//		cout<<i<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	//24
	return 0;
}

