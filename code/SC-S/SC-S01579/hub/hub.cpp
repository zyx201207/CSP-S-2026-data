#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int> 
using namespace std;
const int N = 5100,mod=1e9+7,inf = 1e18;
mt19937 rnd(time(0));
int c,T;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
    	int p=rnd()%2;
    	cout<<p<<"\n";
	}
    return 0;
}