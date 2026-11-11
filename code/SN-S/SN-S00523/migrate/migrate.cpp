//程楚焱 SN-S00523 延安市新区培文学校 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long a[N];
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=n-1;j>=0;j--){
				//cout<<j-i-1<<" "<<a[j]-a[i]<<" ";
				if(j-i-1==2&&a[j]-a[i]>d&&a[j]-a[i]/d<=1)ans++;
				if(j-i-1<2){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
