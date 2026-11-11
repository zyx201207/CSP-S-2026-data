#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],yu=2147483647,Max;
int ans;
inline int read(){
	int num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
void dfs(int sum,int last,int cnt){
	if(last>n) return;
	if(cnt>m){
		ans=max(ans,sum);
		return;
	}
	dfs(sum,last+1,cnt);
	for(int i=last+1;i<=n;i++){
		dfs(sum&a[i],i,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		yu&=a[i];Max=max(Max,a[i]);
	}
	if(m==n){
		cout<<yu<<endl;
		return 0;
	}
	else if(m==1){
		cout<<Max<<endl;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		dfs(2147483647,0,1);
		cout<<ans<<endl;
		return 0;
	}
}
/*
00001
00011
00111
01111
11111
11111
*/
