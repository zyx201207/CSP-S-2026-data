#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using pii = pair<int,int>;
const int M = 5e5 + 505;
vector<pii> g[M];
int zj[M];
int f[M];
int h[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 0;i < t;i++){
	    int n,d;
	    cin>>n>>d;
	    for(int j = 1;j <= n;j++){
	    	cin>>h[j];
		}
		if(h[2] - h[1] == h[1] - h[0]){
			cout<<(int)pow(2,n - 1)<<endl;
		}else{
			cout<<i<<endl;
		}
	}
	return 0;
}