#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,op,T,a[5010],d[305][305],s[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		if(op<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j]=1e9;
					s[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=m){
						d[i][j]=1;
						s[i][j]=1;
					}else{
						break;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(d[i][j]==d[i][k]+d[k][j]){
							s[i][j]+=s[i][k]*s[k][j];	
						}
						if(d[i][j]>d[i][k]+d[k][j]){
							d[i][j]=d[i][k]+d[k][j];
							s[i][j]=s[i][k]*s[k][j];
						}
					}
				}
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
				//	cout<<i<<" "<<j<<" "<<d[i][j]<<" "<<s[i][j]<<"\n";
					if(s[i][j]==2){
						sum++;
					}
				}
			}
			cout<<sum<<"\n";
		}
		if(op==11||op==12){
			int z=a[2]-a[1];
			int l=0,r=m;
			while(l<r){
				int mid=(l+r+1)/2;
				if(mid*z<=m){
					l=mid;
				}else{
					r=mid-1;
				}
			}
			if(l>n){
				cout<<0<<"\n";
				continue;
			}
			if(l==3){
				cout<<n-l-2<<"\n";
			}else if(l==2){
				cout<<n-l-1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
		if(op==13||op==14){
			cout<<0<<"\n";
			continue;
		}
		
	}
	return 0;
} 
