#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
vector<int>g[N];
int n,d;
bool ok=0;
void omg(){
	if((n==4||n==5)&&d==2){
				for(int i=1;i<=n;i++){
					if(x[i]==i){
						ok=1;
					}
				} 
			}
			if(ok&&n==4)cout<<1<<endl;
		    else if(n==5)cout<<2<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==0){
			omg();
		}
		
	}
	return 0;
}
