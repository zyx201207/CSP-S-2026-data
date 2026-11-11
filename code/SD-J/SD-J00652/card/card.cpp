#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[500005],ans,t[500005];
bool dis[3005];
stack <int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(dis,false,sizeof(dis));
		for(int j=i;j<=n;j++){
			
			if(dis[a[j]]==false){
				dis[a[j]]=true;
				st.push(a[j]);
			}else{
				while(true){
					int u=st.top();
					if(u==a[j]){
						
						break;
					} else{
						st.pop();
						
						dis[u]=false;
					}
				}
				
			}
		}
		while(!st.empty()){
			int u=st.top();
			st.pop();
			t[u]++;
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
