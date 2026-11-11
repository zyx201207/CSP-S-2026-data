#include<bits/stdc++.h>
using namespace std;
#define bpc __builtin_popcount
const int N=2e5+1;
int a[N],n,m,ans=0,sa[N],ba[N+2];
struct node{int a,b;}s[N];
bool cmp(node x,node y){return x.b>y.b;}
map<int,int> mp;
void dfs(int step,int cnt,int sum){
	if(step>n){
		if(cnt==m) ans=max(ans,sum);
		return ;
	}
	dfs(step+1,cnt,sum);
	if(sum==-1) dfs(step+1,cnt+1,a[step]);
	else dfs(step+1,cnt+1,sum&a[step]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int pw=1;
	for(int i = 1;i<=30;i++) mp[pw-1]=1,pw<<=1;
	mp[pw-1]=1;
	cin>>n>>m;
	bool spj1=1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(!mp.count(a[i])) spj1=0;
	}
	if(n<=20){
		dfs(1,0,-1);
		cout<<ans;
		return 0;
	}//1-5 25pts
	else if(m==1){
		for(int i = 1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}//6 5pts
	else if(m==n){
		for(int i = 1;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}//7 5pts
	else if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}//8-10 15pts
	else if(m==n-1){
		sa[1]=a[1],ba[n]=a[n];
		for(int i = 2;i<=n;i++) sa[i]=sa[i-1]&a[i];
		for(int i = n-1;i;i--) ba[i]=ba[i+1]&a[i];
		ans=max(ans,sa[n-1]),ans=max(ans,ba[2]);
		for(int i = 2;i<n;i++) ans=max(ans,sa[i-1]&ba[i+1]);
		cout<<ans;
		return 0;
	}//11-12 10pts
	else if(spj1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[n-m+1];
		return 0;
	}//13 5pts
	else{
		for(int i = 1;i<=n;i++) s[i]={a[i],bpc(a[i])};
		sort(s+1,s+n+1,cmp);
		for(int i = 1;i<=m;i++) ans^=s[i].a;
		cout<<ans;
		return 0;
	}//14-20 maybe can't get pts
	return 0;
}

