#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005];
bool vis[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int bo=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			cnt[i]++;
			vis[i]=true;
		}
		for(int ii=1;ii<=n;ii++){
			cin>>a[ii];
			if(bo==0&&a[ii]>=j){
				for(int i=m;i>=a[ii];i--){
					cnt[i]--;
					bo=1;
				}
			}
			else{
				cnt[a[ii]]++;
				if(vis[a[ii]]==true){
					cnt[a[ii]]=0;
					vis[a[ii]]=false;
				}
				else vis[a[ii]]=true;
			}
		}
		bo=0;
		for(int i=1;i<=n;i++){
			vis[a[i]]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
