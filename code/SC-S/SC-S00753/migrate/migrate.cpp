#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	int n;
    	long long d,a[20005],ans;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	long long l=a[2]-a[1];
        bool end=1;
    	for(int i=2;i<=n-1;i++) if(l!=a[i+1]-a[i]) end=0;
    	if(end==1){
    		if(l*2>=d||n<=3) cout<<0;
    		else cout<<n-3;
		}
		else{
			for(int i=1;i<=n-2;i++){
				if(a[i+2]-a[i]<=d){
					ans++;
					int k1=1,k2=1;
					for(int j=i-1;j>=1;j--){
						if(k1==2&&a[j+1]-a[j]<=d&&a[j+2]-a[j]>d) ans++;
						else if(a[j+2]-a[j]<=d) k1++;
						else break;
						if(k1>2) break;
					}
					for(int j=i+2;j<=n-1;j++){
						if(k2==2&&a[j+1]-a[j]<=d&&a[j+2]-a[j]>d) ans++;
						else if(a[j+2]-a[j]<=d) k2++;
						else break;
						if(k2>2) break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}