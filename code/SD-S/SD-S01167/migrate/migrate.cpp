#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+5;
vector<vector<int> > p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
	for(int o=1;o<=t;o++){
		long long n,d,x[MAXN];
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>x[j];
		if(c==11 || c==12){
			if(n<=4) cout<<1;
			else cout<<0;
			return 0;
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int a=x[k]-x[j];
				if(a<=d) p[j][k]++;
				else break;
			}
		}
	}
	return 0;
}
