#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,qian[200005],hou[200005];
int n,m,fa,rp,vis[5];
bool cifang[200005];
void solve1(int x,long long step,int cnt){
	if(cnt==m){
		ans=max(ans,step);
		return ;
	}
	if(x>n){
		return ;
	}
	solve1(x+1,step,cnt);
	solve1(x+1,step&a[x+1],cnt+1);
}
void solve2(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
}
void solve3(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=(ans&a[i]);
	}
}
void solve4(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
}
void solve5(){
	qian[0]=(long long)pow(2,30)-1; 
	hou[n+1]=(long long)pow(2,30)-1; 
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]&a[i];
	}
	for(int i=n;i>=1;i--){
		hou[i]=hou[i+1]&a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,qian[i-1]&hou[i+1]);
	} 
}
void solve6(){
	ans=a[n-m+1];
}
void solve7(){
	
}
void solve8(){
	for(int i=1;i<=n;i++){
		vis[a[i]]++;
	}
	if(vis[3]){
		if(vis[3]>=m){
			ans=3;
			return ;
		}else if(vis[2]){
			m-=vis[3];
			if(vis[2]>=m){
				ans=2;
				return ;
			}else{
				if(vis[1]){
					ans=1;
					return ; 
				}
			}
		}else if(vis[1]){
			ans=1;
			return ;
		}
	}else{
		if(vis[2]){
			m-=vis[3];
			if(vis[2]>=m){
				ans=2;
				return ;
			}else{
				if(vis[1]){
					ans=1;
					return ; 
				}
			}
		}else if(vis[1]){
			ans=1;
			return ;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<=17;i++){
		cifang[(int)pow(2,i)]=1;
		cifang[(int)pow(2,i)-1]=1;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<4){
			rp++;
		}
		if((a[i]%2==1||a[i]==0)&&cifang[a[i]]==1){
			fa++;
		}
	}
	if(n<=20){//1~5
		solve1(1,(long long)pow(2,30)-1,0);
		solve1(1,a[1],1);
		cout<<ans;
		return 0;
	}
	if(m==1){//6
		solve2();
		cout<<ans;
		return 0;
	}
	if(m==n){//7
		solve3();
		cout<<ans;
		return 0;
	}
	if(m==2){//8~10
		solve4();
		cout<<ans;
		return 0;
	}
	if(m==n-1){//11~12
		solve5();
		cout<<ans;
		return 0;
	}
	if(fa==n){//13
		solve6();
		cout<<ans;
		return 0;
	}
	if(cifang[n]==1&&n%2==0){//14~15
		solve7();
		cout<<ans;
		return 0;
	}
	if(rp==n){//16~17
		solve8();
		cout<<ans;
		return 0;
	}
	solve1(1,(long long)pow(2,30)-1,0);
	solve1(1,a[1],1);
	cout<<ans;
	return 0;
}

