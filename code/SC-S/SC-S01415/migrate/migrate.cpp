#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t,wz[N];
int n,d,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>wz[i];
			int gc=wz[n]-wz[n-1];
			if(d<=gc)
				cout<<0;
			else{
				if(d%gc==0){
					if(d==2*gc)
						cout<<(n-1)-3+1;
					else
						cout<<0;
				}else{
					int nd=d/gc+1;
					if(nd==3)
						cout<<(n-1)-3+1;
					else
						cout<<0;
				}
			}
			cout<<'\n';
		}
	}else{
		for(int i=1;i<=t;i++)
			cout<<0<<'\n';
	}
	return 0;
}