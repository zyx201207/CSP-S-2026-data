#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while (t--){
		ll n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		bool flag1=true;
		ll sum=x[2]-x[1];
		for (int i=2;i<=n;i++){
			if (x[i]-x[i-1]!=sum) flag1=false;
			
		}
		if (flag1==true){
			if(sum>d){
				cout<<0<<endl;
			}
			else if (sum==d){
				cout<<0<<endl;
			}
			else{
				ll dis=x[n]-x[1];
				if (dis<=d) cout<<0<<endl;
				else if (d%sum!=0 and d<sum){
					cout<<0<<endl;
				}
				else{
					if (d%sum==0){
						
						cout<<(dis-d)/sum<<endl;
					}
					else if (d%sum!=0 and d<2*sum){
						cout<<0<<endl; 
						
					}
					else{
						ll k=(d-1)/sum;
						
						cout<<k-1+ceil((dis-d)/sum)<<endl;
					}
				}
			}
			continue;
		} 
		for (int i=1;i<=n;i++){
			for (int j=n;j>=1;j--){
				if (i>=j) break;
				ll dis=x[j]-x[i];
				if (dis<=d){
					cout<<0<<endl;
					break;
				}
				else {
					cout<<0<<endl;
					
				}
			}
		}
		for (int i=1;i<=n;i++){
			x[i]=0;
		}
	}
	
	return 0;
	
}
