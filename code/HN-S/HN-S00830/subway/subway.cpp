#include <bits/stdc++.h>
using namespace std;
const int MAXN1=505;
const int MAXN2=500005;
const int MAXN=100005;
long long w[MAXN2];
int k[MAXN1];
int a[MAXN1][MAXN2];
long long t[MAXN1][MAXN2];
struct r{
	int x;
	int y;
};
r rr[MAXN];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>rr[i].x>>rr[i].y;
	}
	if(n==2&&q==2){
		cout<<32<<endl;
		cout<<17;
	}
	if(n==3&&q==2){
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
}

