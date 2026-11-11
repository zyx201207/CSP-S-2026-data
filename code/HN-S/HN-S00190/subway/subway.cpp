#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct Node{
	int first,second;
}s[N];
int c,n,m,d,p;
int x_r[N],y_r[N];
int w[N];
int ans=0x3f3f3f3f;
int sum=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>s[j].first>>s[j].second;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x_r[i]>>y_r[i];
	}
	for(int i=1;i<=p;i++){
		for(int j=x_r[i];j<=y_r[i];j++){
			sum=w[j]+s[j].second;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}
