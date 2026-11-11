#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],d[M],c[N];
vector<int> b[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[a[i]].push_back(i);
	}
	for(int j=1;j<=n;j++){
		int y=n,h=j;
		for(int i=j;i<=n;i++){
			int ec=lower_bound(b[a[i]].begin(),b[a[i]].end(),j)-b[a[i]].begin();
			if(ec<b[a[i]].size()){
				y=min(y,b[a[i]][ec]);
				if(b[a[i]][ec]<i){
					h=max(h,i);
				}
			}
		}
		if(h>y&&a[h]==a[y])h++;
		if(h<=y)h=y+1;
//		cout<<j<<"->"<<y<<" ; "<<h<<"->"<<n<<"\n";
		c[j]++,c[y+1]--;
		c[h]++,c[n+1]--;
//		for(int i=j;i<=y;i++){
//			d[a[i]]++;
//		}for(int i=h;i<=n;i++){
//			d[a[i]]++;
//		}
	}c[0]=0;
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
		d[a[i]]+=c[i];
	}for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}cout<<'\n';
	return 0;
}
