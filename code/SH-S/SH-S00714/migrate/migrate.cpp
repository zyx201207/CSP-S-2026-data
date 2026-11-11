#include<bits/stdc++.h>
using namespace std;
#define N 2000008
long long d,a[N];
int c,t,n,lstps;
long long res;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;lstps=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int fr=lower_bound(a+1,a+i+1,a[i]-d)-a;
			int scdps=lower_bound(a+1,a+i+1,a[fr+1]-d)-a;
			int thdps=lower_bound(a+1,a+i+1,a[fr+2]-d)-a;
			if(thdps-scdps>0){
				res+=thdps-lstps;
				lstps=thdps;
			}
		}
		cout<<res<<'\n';res=0;
	}
}
/*
0 1
5 3
0 3 5 6 7
0 1
4 2
1 2 3 4
*/
