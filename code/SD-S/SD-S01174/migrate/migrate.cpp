#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long cnt=0;
		long long y=0,maxx=0;
		y=x[n]-x[1];
		if(y%d==0) y/=d;
		else y=y/d+1;
		for(int l=1;l<=y;l++){
			for(int i=1;i<=n;i++){
				int j=i+2+l;
				long long s=x[j]-x[i];
				if(l*d<s&&s<(l+1)*d) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}	
	return 0;
} 
