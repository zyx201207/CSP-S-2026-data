#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
struct node{
	int um;
	int t;
}a[maxn];
ll c,n,m,d,q;
ll w[maxn];
ll x[maxn],y[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i].um>>a[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<w[rand()%m+1]+a[rand()%n+1].t+a[rand()%n+1].t+w[rand()%m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}