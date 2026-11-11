#include<bits/stdc++.h>
using namespace std;
int a[500001],n,m,x,lastans[300001];
vector<int> qwer;
map<signed,signed> f[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int q[n+1]={0},zz=0;
		for(int j=i;j<=n;j++){
			if(f[i][a[j]]) zz=f[i][a[j]];
			else q[++zz]=a[j],f[i][a[j]]=zz;
		}
		for(int j=1;j<=zz;j++) qwer.push_back(q[j]);
	}
	for(auto i:qwer) lastans[i]++;
	for(int i=1;i<=m;i++) cout<<lastans[i]<<' ';
	return 0;
}
