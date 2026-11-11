#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,t;
}sss[500010];
long long c,d,p,n,m,b[100010][2],w[500010];
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
		for(int j=1;j<=k;j++){
			cin>>sss[j].a>>sss[j].t;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=1;i<=p;i++){
		cout<<sss[b[i][0]].a+sss[b[i][0]].t+sss[b[i][1]].a+sss[b[i][1]].t<<endl;
	} 
	return 0;
}