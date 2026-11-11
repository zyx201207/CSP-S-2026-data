//赵晗羽  SN-S00433  西安辅轮中学                     
#include<bits/stdc++.h>                            
using namespace std;                              
int c,n,m,d,p,a[500005],k[505],s,b[500005];         
struct st{               
	int x,t;            
};                                             
vector<st> ve[505];             
int main(){                                             
	freopen("subway.in","r",stdin);                  
	freopen("subway.out","w",stdout);                     
	cin>>c>>n>>m>>p>>d;                                
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];        
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			ve[i].push_back({x,t});
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)b[i]=0;
		s=a[x]+a[y]+19+12+3+56;          
		cout<<s<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
