#include<bits/stdc++.h> 
using namespace std;
struct line{
	int a,t;
};
int k,c,n,m,d,q,tl[500005],dis[205][205],tr[205][500005];
set<line>a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tl[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;i++){
			int te;
			cin>>te;
			cin>>tr[i][te]
		}
	}
	return 0;
}