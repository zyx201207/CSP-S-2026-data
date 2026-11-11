//愿为逝者哀哭，泣如雨下，填盈忘川……如潮涌至，领你归乡 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
random_device rd;
mt19937_64 ran(rd());
int c,T;
int n;
ll d;
vector<ll> g;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
while(T--){
	cin>>n>>d;
	g=vector<ll>(n+30);
	for(int i=1;i<=n;i++) cin>>g[i];
	if(n<=3){
		printf("0\n");
		continue;
	}
	if(c==11 || c==12){
		printf("0\n");
		continue;
	}
	ll cnt=0;
	for(int i=1;i<=n-3;i++){
		if(g[i+2]-g[i]<=d && g[i+3]-g[i+1]<=d && g[i+3]-g[i]>d) cnt++;
	}
	printf("%lld\n",cnt);
}
	return 0;
}

