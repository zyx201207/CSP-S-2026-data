#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000005;
long long c,T,n,k;
struct ct{
	int u,v;
}city[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>city[i].u>>city[i].v;
	}
	return 0;
}
