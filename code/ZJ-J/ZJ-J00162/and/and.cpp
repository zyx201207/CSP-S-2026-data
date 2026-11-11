#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
struct S{
	int x,y;
}a[200010];

bool cmp(S a,S b){
	return a.y>b.y;
}

bool cmpb(S a,S b){
	return a.x>b.x;
}

int ma=0;

void dfs(int x,int st,int cnt){
	if(x==n&&st<m)return;
	if(st==m){
		ma=max(ma,cnt);
		return;
	}
//	cout<<x<<' '<<st<<' '<<cnt<<'\n';
	dfs(x+1,st,cnt);
	dfs(x+1,st+1,cnt&a[x].x);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	bool fa=true,f4=true,fb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int x=a[i].x;
		if(x!=x-1)fb=false;
		if(x>=4)f4=false;
		ma=max(ma,x);
		int cnt=0,o=0;
		while(x){
			if(x%2==1)cnt++;
			x/=2;
			o++;
		}
		if(cnt!=o)fa=false;
		a[i].y=cnt;
	}
	sort(a+1,a+1+n,cmp);
	if(n==m){
		int ans=a[1].x;
		for(int i=2;i<=n;i++){
			ans=ans&a[i].x;
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<ma;
	}
	else if(m==2){
		ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				ma=max(ma,a[i].x&a[j].x);
			}
		}
		cout<<ma;
	}
	else if(m==n-1){
		ma=0;
		int ans=a[1].x;
		for(int i=2;i<=m;i++){
			ans=ans&a[i].x;
		}
		for(int i=1;i<=n;i++){
			ma=max(ma,ans|a[i].x);
		}
		cout<<ma;
	}
	else if(fa){
		cout<<a[m].x;
	}
	else if(f4){
		map<int,int>mp;
		mp[0]=0;
		mp[1]=0;
		mp[2]=0;
		mp[3]=0;
		for(int i=1;i<=n;i++){
			mp[a[i].x]++;
		}
		if(m<=mp[3]){
			cout<<3;
			return 0;
		}
		m-=mp[3];
		if(m<=mp[2]){
			cout<<2;
			return 0;
		}
		cout<<0;
	}
	else if(fb&&n%2==0){
		sort(a+1,a+1+n,cmpb);
		int ans=a[1].x;
		for(int i=2;i<=m;i++){
			ans=ans&a[i].x;
		}
		cout<<ans;
	}
	if(n<=20){
		ma=0;
		for(int i=1;i<=n-m;i++){
			dfs(i,1,a[i].x);
		}
		cout<<ma;
	}
	else{
		int ans=a[1].x;
		for(int i=2;i<=m;i++){
			ans=ans&a[i].x;
		}
		cout<<ans;
	}
}
