#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int g[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>c[i];
		len+=g[i];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<=j){
		if(g[i]==g[j]){
			ans+=(c[i]!=c[j])*g[i];
			g[i]=g[j]=0;i++;j--;
		}else if(g[i]<g[j]){
			ans+=(c[i]!=c[j])*g[i];
			g[j]-=g[i];g[i]=0;i++;
		}else if(g[i]>g[j]){
			ans+=(c[i]!=c[j])*g[j];
			g[i]-=g[j];g[j]=0;j--;
		}
	}
	cout<<ans;
	return 0;
}
