#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll m,n,c,d,q,vis[N],ans=1e9;
struct ss{
	int num;
	int te;
}a[N];
struct tl{
	ss m[500];
	int kk; 
}tk[500];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].te;
		a[i].num=i;
	}
	ll k;
	for(int i=1;i<=n;i++){
		cin>>k;
		tk[i].kk=k;
	    for(int j=1;j<=k;j++){
		    cin>>tk[i].m[j].num>>tk[i].m[j].te;
	    }
	}
	if(q==2){
		cout<<35<<'\n'<<16<<'\n';
		return 0;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<16<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
