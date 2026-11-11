//赵晗羽  SN-S00433  西安辅轮中学  
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[600005],ans,b[600005];
struct st{
	int v,l;
}c[70005],f[600005];
bool ck(int x){
	int e=x,p=0,s=0;
	while(e>1){
		e--;
		s+=b[++p]*(x-e);	
	}
	return s<=m;
}
bool cmp(st a,st b){
	if(a.v!=b.v)return a.l>b.l;
	else return a.v<b.v;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int md=(l+r)/2;
		if(ck(md)){
			l=md+1;
			ans=max(ans,md);
		}else r=md-1;
	}
	int y=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[ans])y=i;
	}
	cout<<y;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
