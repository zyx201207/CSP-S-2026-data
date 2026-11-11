#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t;
int n;
bool f=true; //是否性质A 
ll d,x[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]){
				f=false;
//				cout<<"oh no!!!";
			} 
		}
		if(f){
			ll dif=x[2]-x[1];
			for(int i=2;i<n;i++){ //间隔为i个block
				ll maxn=min(i*dif,d/dif); //一次最多走多少块
				if(maxn*dif==0||(x[i+1]-x[1])%(maxn*dif)==0) {
					continue;  //正好走完
//					cout<<"Why!!!\n";
				}
				int blo=i/maxn;  //走了完整的多少块 
				if(blo==1){
					int other=i-maxn;
					if(abs(other-maxn)>=1) continue;
					ans+=n-i;
//					cout<<"i="<<i<<' ';
				}
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/


//气死我了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！特殊性质没写出来！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
