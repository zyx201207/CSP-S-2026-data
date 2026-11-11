#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=1e8+5;
int n,tot,ans,a[N],f[N];
char c[N],t[M];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		f[i]=f[i-1]+a[i];
		for(int j=f[i-1];j<=f[i];j++){
			t[j]=c[i];
		}
	}
	tot=f[n]-1;
	if(tot<=M){
		for(int i=0;i<=tot/2;i++){
			if(t[i]!=t[tot-i]) ans++;
		}
		cout<<ans;		
	}else{
		cout<<0;//Give me some points,my dear dad!
	}
	return 0;
}