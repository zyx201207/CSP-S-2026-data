#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d||(a[j]-a[i])%d==0||a[i]-a[j]>(j-i)*d||(a[i]-a[j]-((a[i]-a[j])/d-1)*d>0&&d!=2)){
					continue;
				}else{
					if(d==2){
						if(a[j]-a[i]==3&&j-i>1)
						cnt++;
					}else{
						cnt++;
					}
					
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}