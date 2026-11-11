#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
int ans=0,sum=0;
struct node{
	int id,tm;
};
vector<node> sb[501];
int vis[N]; 
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}void dj(int l,int r){
	if(vis[l]==1) return;
	if(l==r){
		sum=min(ans,sum);
		return;
	}
	vis[l]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<sb[i].size();j++){
			if(sb[i][j].id==l){
				ans=ans+sb[i][j].tm;
				for(int j=0;j<sb[i].size();j++){
					dj(sb[i][j].id,r);
				}
				ans=ans-sb[i][j].tm;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int id=read(),tm=read();
			sb[i].push_back({id,tm});
		}
	}while(q--){
		sum=0;
		ans=0;
		int l=read(),r=read();
		dj(l,r);
		cout<<sum+w[l]+w[r]<<endl;
	}
	return 0;
}

