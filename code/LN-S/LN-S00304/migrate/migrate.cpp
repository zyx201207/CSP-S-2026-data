#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,x[2000010],c,t,far[2000010];
bool check(int s,int c){
	if(x[c]-x[s]>d) return false;
	return true;
}
int erfen(int s,int l,int r){
	if(l==r) return l;
	int mid=(l+r+1)>>1;
	if(!check(s,mid)) return erfen(s,l,mid-1);
	return erfen(s,mid,r);
}
void majn(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	for(int i=1;i<=n;i++)
	far[i]=erfen(i,i,n);
	for(int i=1;i<=n;i++){
		if(far[far[i]-2]<i) continue;
		int aaa=far[far[i]-1],kkk=far[far[i]-2];
		ans+=max(0ll,aaa-kkk);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	majn();
	return 0;
}
