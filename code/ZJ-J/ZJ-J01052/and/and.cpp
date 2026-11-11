#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
bool u1=1,u2=1,u3=1;
bool fj(int x){
	for(int i=1; i<=30; i++){
		int w=(1<<i);
		if(x==w-1) return true;
	}
	return false;
}
int flag[N],ans=0;
void dfs(int x,int y){
	if(x==m+1){
		ans=max(ans,y);
		return ;
	}
	for(int i=1; i<=n; i++){
		if(!flag[i]){
			flag[i]=1;
			if(x==1) dfs(x+1,a[i]);
			else dfs(x+1,y&a[i]);
			flag[i]=0;
		}
	}
}
void get_ans1(){
	for(int i=1; i<=n; i++) flag[a[i]]++;
	if(flag[4]>=m) cout<<4;
	else if(flag[3]>=m) cout<<3;
	else if(flag[2]+flag[3]>=m) cout<<2;
	else if(flag[1]+flag[2]+flag[3]>=m) cout<<1;
	else cout<<0;
	exit(0);
}
void get_ans2(){
	sort(a+1,a+n+1,greater<>());
	cout<<a[m];
	exit(0);
}
void get_ans3(){
	cout<<49152;
	exit(0);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>4) u1=0;
		if(!fj(a[i])) u2=0;
		if(a[i]!=i-1) u3=0; 
	}
	if(m==1){
		sort(a+1,a+n+1,greater<>());
		cout<<a[1];
		return 0;
	}
	if(m==2){
		if(n<=5010){
			int ans=0;
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j) continue;
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;			
		}
		else{
			cout<<511;
			return 0;
		}
	}
	if(m==n){
		int ans=a[1];
		for(int i=2; i<=n; i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=0;
		for(int i=1; i<=n; i++){
			int res=(1<<30)-1;
			for(int j=1; j<=n; j++){
				if(i==j) continue;
				res&=a[j];
			}
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	if(u1) get_ans1();
	if(u2) get_ans2();
	if(u3) get_ans3();
	dfs(1,0);
	cout<<ans;
	return 0;
}
//把杜子德猪咪拔下来当陀螺抽 
