#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,b[200100],t,k,f[200100],f_2[200100];
string a[200100];
string change(int x){
	string s="";
	while(x>0){
		s+=(x%2+'0');
		x/=2;
	}
	return s;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>b[i];
		a[i]=change(b[i]);
	}
	for(i=1;i<=n;i++) k=a[i].size(),t=max(t,k);
	for(i=1;i<=n;i++){
		for(int j=a[i].size();j<t;j++) a[i]+='0';
	}
	int kkksc03=n;
	while(kkksc03>m&&t>=0){
		int kkksc03_2=kkksc03;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			if(a[i][t]=='0'&&!f_2[i]) kkksc03_2--,f[i]=1;
		}
		if(kkksc03_2>=m){
			for(i=1;i<=n;i++) f_2[i]+=f[i];
			kkksc03=kkksc03_2;
		}
		t--;
	}
	int ans;
	for(i=1;i<=n;i++)
		if(!f_2[i]){
			ans=b[i];
			break;
		}
	for(;i<=n;i++)if(!f_2[i])ans&=b[i];
	cout<<ans;
	return 0;
}
