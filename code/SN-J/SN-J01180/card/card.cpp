#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	int n,m,a[500005],cnt[500005],vis,ans[500005];
	void work(){
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			vector<int> q(0);
			memset(cnt,0,sizeof(cnt));
			vis=0;
			for(int j=i;j<=n;j++){
				int k=a[j];
				if(cnt[k]==0){
					q.push_back(k);
					cnt[k]++;
				}
				else{
					for(int p=0;p<q.size();p++){
						if(q[p]==k){
							vis=p;
							break;
						}
					}
					for(int p=vis;p<q.size();p++){
						cnt[q[p]+1]=0;
						q[p]=0;
					}
					q.push_back(k);
					cnt[k]++;
				}
			}
			for(int i=0;i<q.size();i++){
				ans[q[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		//Qaaxaap,Pulsar,Vesperon
		//114514
		//feropen
		//foropen
		//wowaka
		//kafka
		//Aha
		//Hatsune Miku
		//Kasane Teto 
	}
}
int main(){
	ios::sync_with_stdio(0);
	return Vesperon::work() ,0;
}
