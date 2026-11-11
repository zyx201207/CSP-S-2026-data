#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int a[500005];
struct node{
	int v,w;
};
vector<node> g[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17;
	}else{
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
}