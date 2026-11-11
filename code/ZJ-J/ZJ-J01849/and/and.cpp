#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll n,m,a[N],b[N],maxn=-1,ans;
ll s1=-1,s2,s3=-1;
bool vis[N],f1=true,f2=true;
void dfs(int t){
	if(t>m){
		ll sum=b[1];
		for(int i=1;i<=m;i++) sum&=b[i];
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true; b[t]=a[i];
		dfs(t+1);
		vis[i]=false;
	}
}
string s[N];
map<string,int> M;
void biary(int id,ll x){
	int cnt=31;
	string t;
	while(x!=0){
		t+=(char)(x%2+'0');
		x/=2; cnt--;
	}
	for(int i=cnt;i>=0;i--) t+='0';
	for(int i=t.size()-1;i>=0;i--) s[id]+=t[i];
}
bool cmp(string x,string y){return x>y;}
bool check(ll x){
	ll xx=1;
	if(x==1) return true;
	while(xx-1<=x){
		if(xx-1==x) return true;
		xx*=2;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i-1) f1=false;
		if(check(a[i])==false) f2=false;
		biary(i,a[i]); M[s[i]]=a[i];
		s1=max(s1,a[i]);
		if(i==1) s2=a[i];
		else s2&=a[i];
	}
	if(m==1){cout<<s1; return 0;}
	if(m==n){cout<<s2; return 0;}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				s3=max(s3,a[i]&a[j]);
			}
		cout<<s3;
		return 0;
	}
	if(f1==true||f2==true){
		sort(s+1,s+n+1,cmp);
		ans=M[s[1]];
		for(int i=2;i<=m;i++) ans&=M[s[i]];
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",maxn);
	return 0;
}