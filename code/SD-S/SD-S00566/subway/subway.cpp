#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll c,n,m,d,q,k[N],w[N],a[505][1000],t[505][1000];
int ans=0;
vector<int> v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int f,a,x;
		for(int i=1;i<=k[i];i++){
			cin>>a>>x;
			if(i>1){
				v[f].push_back(a);
				v[a].push_back(f); 
			}
			f=a;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cout<<x*y;
	}
	return 0;
}
