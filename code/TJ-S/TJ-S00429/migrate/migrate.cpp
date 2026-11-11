#include<iostream>//RP++
using namespace std;
int c,t,n,l,r;
long long d,arr[2000005],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		l=1,r=n+1;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			if(i>=4&&(arr[i-1]-arr[i-3]<=d&&arr[i]-arr[i-2]<=d&&arr[i]-arr[i-3]>d)){
				//DW
				int j=i-3;
				for(;j>=2;j--){
					if(arr[j]-arr[j-1]>d) break;
					if(arr[j]-arr[j-2]<=d){
						j--;
						break;
					}
				}
				j-=i-4;
				int k=i+2;
				for(;k<=n;k++){
					if(arr[k-1]-arr[k-2]>d) break;
					if(arr[k]-arr[k-2]<=d){
						k++;
						break;
					}
				}
				k-=i+1;
				ans+=max(0ll,1ll*j*k);
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
} 
