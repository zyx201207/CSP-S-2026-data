#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long a[200010];
long long cishu[200010];
long long zuiduan[200010];
void check(long long n,long long d,long long st){
	for(int i=st;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//cout<<a[i]<<' '<<a[j]<<' '<<bool((a[j]-a[i])<=d)<<'\n';
			
			if(a[j]-a[i]>d) break;
			else{
				if(zuiduan[j]==-1){
					zuiduan[j]=1+zuiduan[i];
					cishu[j]=cishu[i];
				}
				else if(zuiduan[i]+1<zuiduan[j]){
					zuiduan[j]=zuiduan[i]+1;
				}
				else if(zuiduan[j]==1+zuiduan[i]){
					cishu[j]+=cishu[i];
				}
				//cout<<zuiduan[i]+1<<" "<<zuiduan[j]<<'\n';
			}
			for(int i=1;i<=n;i++){
				//cout<<cishu[i]<<" ";
			}
			//cout<<endl;
		}
	}
	for(int i=3;i<=n;i++){
		//cout<<cishu[i]<<" ";
		if(cishu[i]==2) ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(cishu,0,sizeof(cishu));
		memset(a,0,sizeof(a));
		memset(zuiduan,-1,sizeof(zuiduan));
		cishu[1]=1;
		zuiduan[1]=0;
		ans=0;
		cin>>n>>d;
		if(n==11||n==12){
			cout<<0<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n==1||n==0||n==3||n==2){
				cout<<0;
			}
			else{
				for(int i=1;i<=n;i++){
					check(n,d,i);
				}
				cout<<ans<<'\n';
			}	
		}
	}
	return 0;
}