//rp++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
random_device rd;
mt19937_64 ran(rd());
int c,T;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
while(T--){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
	}
	printf("%d\n",(int)ceil(1.0*((ran())%100)/100 * n));
}
	return 0;
}

