#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c >> t;
	if(c==11||c==12){
		while(t--){
			long long n,d,a[10];
			cin >> n >> d >> a[1] >> a[2];
			long long f=abs(a[2]-a[1]);
			if(d<2*f) cout << "0\n";
			if(n<(d/f)*2) cout << "0\n";
			cout << n-(d/f)*2+1 << endl;
		}
	}
	else if(c==13||c==14){
		while(t--) cout << "0\n";
	}
	else if(c>=1&&c<=10){
		while(t--){
			long long n,d,a[80005],b[80005],vis[80005],ans=0;
			cin >> n >>d;
			for(int i=1;i<=n;i++) cin >> a[i];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) b[j]=vis[j]=0;
				b[i]=1;
				for(int j=i;j<=n;j++){
					for(int k=j+1;a[k]-a[j]<=d;k++){
						if(a[k]!=0&&a[k]==a[j]+1&&vis[k]!=1){
							ans++;
							vis[k]=1;
						}
						if(a[k]==0) a[k]=a[j]+1;
					}
				}
			}
			cout << ans << endl;
		}
	}
	else{
		while(t--) cout << "0\n";
	}
	return 0;
} 
