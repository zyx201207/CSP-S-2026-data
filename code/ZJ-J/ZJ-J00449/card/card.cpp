#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2010000],b[2010000],f[2010000],F=1;
stack<int>z;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1])F=0;
	}
	if(n>10000&&m>2&&!F){
		cout<"good luck ccf~";
		return 0;
	}
	if(F&&n>5000){
		for(int i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	if(m==2&&n>5000){
		for(int i=1;i<=n;i++){
			if(a[i]==1||a[n]==1)b[1]++;
			if(a[i]==2||a[n]==2)b[2]++;
		}
		cout<<b[1]<<" "<<b[2];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int i2=1;i2<=m;i2++)f[i2]=0;
		for(int i2=i;i2<=n;i2++){
			if(!f[a[i2]]){
				z.push(a[i2]);
				f[a[i2]]=1;
			}
			else{
				while(z.top()!=a[i2]){
					f[z.top()]=0;
					z.pop();
				}
			}
		}
		while(!z.empty()){
			int x=z.top();
			b[x]++;
			f[x]=0;
			z.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
