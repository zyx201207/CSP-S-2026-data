#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int n,m;
int ans,res,cnt;
int a[N],pre[N],suf[N];
bool v[N];
string s[N];
set<int> st;
string Get_wwq(int x){
	string str="";
	while(x){
		if(x&1) str=str+"1";
		else str=str+"0";
		x>>=1;
	}
	for(int i=str.size();i<32;i++) str=str+"0";
	reverse(str.begin(),str.end());
	return str;
}
void dfs(int id,int res,string vis){
	if(id==m+1){
		ans=max(res,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]=='0'){
			vis[i]='1';
			if(id==1) dfs(2,a[i],vis);
			else dfs(id+1,res&a[i],vis);
			vis[i]='0';
		}
	}
}
bool checkA(){
	for(int i=0;i<=31;i++) st.insert((1<<i));
	for(int i=1;i<=n;i++){
		if(!st.count(a[i]+1)) return false;
	}
	return true;
}
void solve1(){
	string vis;
	for(int i=1;i<=n+1;i++) vis+='0';
	dfs(1,0,vis);
	cout<<ans;
}
void solve2(){
	for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	cout<<ans;
}
void solve3(){
	for(int i=1;i<=n;i++){
		if(i==1) ans=a[i];
		else ans=ans&a[i];
	}
	cout<<ans;
}
void solve4(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
void solve5(){
	pre[1]=a[1],suf[n]=a[n];pre[0]=pre[n+1]=suf[n+1]=4294967295;
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]&a[i];
	for(int i=n-1;i>=1;i--) suf[i]=suf[i+1]&a[i];
	for(int i=1;i<=n;i++) ans=max(ans,pre[i-1]&suf[i+1]);
	cout<<ans;
}
void solve6(){
	sort(a+1,a+1+n);
	ans=a[n];cnt++;
	for(int i=n-1;i>=1;i--){
		ans=ans&a[i];
		cnt++;
		if(cnt==m) break;
	}
	cout<<ans;
}
void solvet(){
	for(int i=1;i<=n;i++) s[i]=Get_wwq(a[i]);
	sort(s+1,s+1+n);
	cnt++;
	for(int i=1;i<=n;i++) reverse(s[i].begin(),s[i].end());
	for(int i=0;i<=31;i++) v[i]=s[n][i]-'0';
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<=31;j++) v[j]=v[j]&(s[i][j]-'0');
		cnt++;
		if(cnt==m) break;
	}
	for(int i=0;i<=31;i++){
		if(v[i]) ans+=(1<<i);
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) solve1();//test 1-5
	else if(m==1) solve2();//test 6
	else if(m==n) solve3();//test 7
	else if(m==2) solve4();//test 8-10
	else if(m==n-1) solve5();//test 11-12
	else if(checkA()) solve6();//test 13
	else solvet();//Ì°ÐÄ 
	return 0;
}
