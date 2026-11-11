#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
int k[N];
struct line{
	int num;
	int time;
}a[5005][5005];

signed main(){
	fast;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].num>>a[i][j].time;
		}
	}
	while(q--){
		int start,final;
		cin>>start>>final;
		bool f1=0,f2=0;
		int l;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j].num==start) f1=1,l=i;
				else if(a[i][j].num==final) f2=1;
			}
		}
		if(f1&&f2){
			int s=w[start]+w[final]+a[l][start].time+a[l][final].time;
			cout<<s<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}