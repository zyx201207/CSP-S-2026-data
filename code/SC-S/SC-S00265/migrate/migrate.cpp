#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long b[2000010];
bool f[2000010];
long long n,d,ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int mx=1;
		for(int i=1;i<(n-1);i++){
			for(int j=i+1;j<n;j++){
				
				if((i*d)>=a[j]-a[0]){
					f[j]=1;
					if(b[j]!=0&&b[j]!=i)b[j]=1e9;
					else b[j]=i;
					mx=max(mx,j);
				}
				if((i*d)<a[j]-a[0]){
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(b[i]-b[i-3]==2)ans++;
		}
		if(n%2==1&&ans!=0)ans++;
		cout<<ans<<endl; 
		ans=0;
		for(int i=0;i<n;i++){
			f[i]=0;
			b[i]=0;
		}
	}
	
	return 0;
}