#include<bits/stdc++.h>
using namespace std;
int n,m,mp[500010];
int a[300010];
int b[300010],sy=0,ans[300010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>mp[i];
	for(int i=1;i<=n;i++){
		while(sy>0){
			a[b[sy]]=0;
			sy--;
		}
		for(int j=i;j<=n;j++){
			if(a[mp[j]]==0){
				a[mp[j]]=1;
				sy++;
				b[sy]=mp[j];
			}
			else{
				while(b[sy]!=mp[j]){
					a[b[sy]]=0;
					sy--;
				}
			}
				
		}
		for(int nw=sy;nw>=1;nw--)
			ans[b[nw]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
