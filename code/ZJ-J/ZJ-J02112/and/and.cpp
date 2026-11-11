#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,d[N],maxx=-1,a[N],t[N],p;
signed A(int a,int b){
	int s1[50],s2[50],l1=1,l2=1,k=0;
	while(a!=0){
		s1[l1]=a%2;
		a/=2;
		l1++;
	}
	while(b!=0){
		s2[l2]=b%2;
		b/=2;
		l2++;
	}
	for(int i=1;i<min(l1,l2);i++){
		if(s1[i]==1&&s2[i]==1) k+=pow(2,i-1);
	}
	return k;
}
void dfs(int k,int f){
	if(k==m+1){
		p=a[1];
		for(int i=2;i<=m;i++){
			p=A(p,a[i]);
		}
		maxx=max(p,maxx);
		return;
	}
	for(int i=f;i<=n;i++){
		if(t[i]!=-1){
			a[k]=d[i];
			t[i]=-1;
			dfs(k+1,i+1);
			t[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	dfs(1,1);
	cout<<maxx;
	return 0;
}
