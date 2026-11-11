#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
int c,n,m,d,q;
ll w[MAXN];
int k[505];
int a[505][MAXN];
int t[505][MAXN];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	vector <int <int>> p[m];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
//			p[j].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
	
		cin>>x>>y;
		ll cost=w[x]+w[y];
		for(int i=1;i<=n;i++){
			int flag=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x || a[i][j]==y){
					flag++;
				}
			}
			if(flag==2){
				cout<<cost<<endl;
				break;
			}
			
		}
	}
	
	return 0;
}

