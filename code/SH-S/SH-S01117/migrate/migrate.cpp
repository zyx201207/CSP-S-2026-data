#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int c,t,n,d,cnt,ll;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n>>d;
		cnt=0;
		ll=0;		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++){
			if((a[i+1]-a[i])<=d){
				ll++;
			} 
			else{
				break;
			}
		}
		for(int i=1;i<=ll;i++){
			for(int j=i+1;j<=ll;j++){
				if(((a[j]-a[i])%d!=0)&&((a[j]-a[i])>d)){
					cnt++;
				}
			} 	
		}
		cout<<cnt<<endl;
	}
	return 0;
}
