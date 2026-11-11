#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005],d;
int check(int x,int y,long long z){
	int cnt=0;
	for(int i=x;i+z<=y;i++){
		if(a[i+z]-a[i]<=d){
			cnt++;
		}
	}
	if(cnt>=3||cnt==1) return 0;
	else if(cnt==2) return 1;
	else return check(x,y,z-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				bool f=1;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						f=0;
						break;
					}
				}
				if(f==0||a[j]-a[i]<=d) break;
				if(check(i,j,j-i-1)){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
