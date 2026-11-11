#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ti=0;ti<t;ti++){
		long long n,d,x[10000],dx[10000],ds[10000],ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		long long fl=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				dx[j]=0;
				ds[j]=0;
			}
			dx[i]=1;
			ds[i]=0;
			for(int j=i;j<n;j++){
				if(dx[j]==2){
					ans++;
				}
				for(int k=j+1;k<n;k++){
					if(x[k]>x[j]+d){
						break;
					}
					if(ds[k]==0||ds[k]==ds[j]+1){
						ds[k]=ds[j]+1;
						dx[k]+=dx[j];
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
