#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans=0;
long long d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long a[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11 || c==12){
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					int x=a[j]-a[i];
					if(x>d){
						x=x%d;
						if(x!=0){
							ans++;
							cout<<a[j]-a[i]<<" "<<i<<" "<<j<<"\n";
						}
					}
				}
			}
		}
		else if(c==13||c==14){
			bool ok;
			int aa;
			for(int i=1;i<=n;i++){
				ok=1;
				for(int j=1;j<=n;j++){
					if(abs(a[j]-a[i])>d){
						ok=0;
					}
				}
				if(ok){
					aa=i;
					break;
				}
		    }
			for(int i=1;i<=n-3;i++){
			    for(int j=i+3;j<=n;j++){
					for(int k=i+1;k<=j;k++){
		    			if(a[j]-a[i]>d && (a[k]-a[i]) <= d  && (a[j]-a[k]) <= d && k!=aa){
		    				ans++;
			    			k=j+1;
						}
				    }
				}
		    }
		}
		cout<<ans<<"\n";
	}
	return 0;
} //13 1 5 4 1 3 5 7 9
