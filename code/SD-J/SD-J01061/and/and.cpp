#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool fl[200010],fl_1[200010];
int lg[200010][35];
vector<int> v;
int ans=-1;
void dfs(int step,int cnt,int x){
	if(step==n+1||cnt==m){
		if(cnt==m){
			ans=max(ans,x);
		}
		return;
	}
//	if(n-step+cnt<m) return;
	dfs(step+1,cnt,x);
	v.push_back(a[step]);
	dfs(step+1,cnt+1,x&a[step]);
	v.pop_back();
}
void tianru(int x,int i){
	int j=0;
	while(x!=0){
		lg[i][j]=x%2;
		x/=2;
		j++;
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		int j=i;
		while(j!=0){
			if(j%2==0) return 0;
			j/=2;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		ans=mx;
	}else if(m==2){
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) mx=max(mx,a[i]&a[j]);
		}
		ans=mx;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}else if(m==n-1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int sum=2147483647;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum&=a[j]; 
			}
			mx=max(mx,sum);
		}
		ans=mx;
	}else if(n<=20) dfs(1,0,2147483647);
	else if(check()) ans=a[n-m+1];
	else{
		for(int i=1;i<=n;i++) tianru(a[i],i);
		bool flag=1;
		for(int j=30;j>=0;j--){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(fl[i]==0&&flag==0) continue;
				if(lg[i][j]==1){
					cnt++;
					fl_1[i]=1;
				}
			}
			if(cnt>m){
				flag=0;
				for(int i=1;i<=n;i++){
					if(fl_1[i]==0) fl[i]==0;
				}
				for(int i=1;i<=n;i++){
					if(fl_1[i]==1) fl[i]==1;
				}
			}
		}
		ans=2147483647;
		for(int i=1;i<=n;i++){
			if(fl[i]==1) ans&=a[i];
		}
	}
	cout<<ans;
    return 0;
}
