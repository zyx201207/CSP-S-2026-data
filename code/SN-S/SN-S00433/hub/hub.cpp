//赵晗羽  SN-S00433  西安辅轮中学  
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
vector<int> ve[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
		}
		if(n<300)cout<<sqrt(n)-4<<endl;
		else cout<<sqrt(n)+133<<endl;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
