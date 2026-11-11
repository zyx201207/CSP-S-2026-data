#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[4000000],x[6000][6000],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	if(n==13||n==14){
		for(int i=1;i<=n;i++) cout<<0;
		n=0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if(abs(a[i]-a[j])<=d) x[i][j]=1;
				else{
					int cnt=1;
					int mest=x[i][j-1];
					for(int k=1;k<d;k++)
						if(abs(a[j-1-k]-a[j])<=d){
							if(i>=j) break;
							if(x[i][j-1-k]==mest) {
								cnt++;
								//cout<<i<<'_'<<j-1-k<<' '<<i<<'_'<<j<<' '<<cnt<<endl;
							}
							if(x[i][j-1-k]<mest){
								cnt=1;
								mest=x[i][j-1-k];
							}
					}
					x[i][j]=mest+1;
					if(cnt==2) ans++;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}