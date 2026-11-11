#include<bits/stdc++.h>
using namespace std;
#define int long long
const int H=2e6+5;
int n,x[H],c,t,d;
bool p(int a,int b){
	for(int i=a+2;i<=b-2;i++){
		if(x[i]-x[a]<=d||x[b]-x[i]<=d){
			return 0;
		}
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(x[i+1]-x[i]<=d&&x[j]-x[j-1]<=d&&x[j]-x[i+1]<=d&&x[j-1]-x[i]<=d&&x[j]-x[i]>d&&p(i,j)&&x[j-1]-x[i+1]<=d){
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}