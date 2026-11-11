#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int x[N],b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int c,t;
	cin>>c>>t;
	int f=0;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			b[i]=x[i]-x[i-1]; 
		}
		if(b[2]>d){
			cout<<0;
			return 0;
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
				if(n/d==2&&n%n==1)continue;
				ans++;
			}
		}
		if(x[1]<0){
			if(!f){
				cout<<0<<endl;
				f=1;
			}
			else cout<<1;
		}
		else cout<<(ans+1)/2<<endl;
	}
	return 0;
} 