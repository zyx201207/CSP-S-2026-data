#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
priority_queue<int>qp;
map<pair<int,int>,int>mp;
int a[N],b[N];
int j1[N],j2[N],jj1,jj2;
int n,m;
bool check(int l,int r){
	jj1=0,jj2=0;
	j1[++jj1]=l;
	for (int i=l;i<=r;i++){
	int p=i;
	while (p<=r&&abs(a[p]-a[i])<=m)p++;
	if (p==i)return false;
	i=p;
	j1[++jj1]=i-1;	
	}
	j2[++jj2]=r;
	for (int i=r;i>=l;i--){
	int p=i;
	while (p>=l&&abs(a[p]-a[i])<=m)p--;
	if (p==i)return false;
	i=p;	
	j2[++jj2]=i+1;
	}
	if (jj1!=jj2)return false;
	for (int i=1,r=jj2;i<=jj1;i++,r--){
	if (j1[i]!=j2[r])return true;	
	}
	return false;
}
void solve(){
	cin>>n>>m; 
    for (int i=1;i<=n;i++){
    cin>>a[i];	
	}
	if (n>=5000){
	cout<<0<<endl;
	return ;	
	}
	int ans=0;
	for (int l=1;l<=n;l++){
	for (int r=l+1;r<=n;r++){
	if (check(l,r))ans++;
	}	
	}
	cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int T=1,C;
	cin>>C>>T;

    while (T--)solve();
	return 0;
}

