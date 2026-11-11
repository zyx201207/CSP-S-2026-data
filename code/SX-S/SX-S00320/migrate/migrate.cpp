#include<bits/stdc++.h>
	
using namespace std;
const int N=5e5+10;
int c;
int n;
long long a[N],d,ans=0;
int f[N];
void init(int l){
	int mx=l;
	for(int r=l;r<n;r++){
		if(r>mx) break;
		if(r==mx){
			for(int k=r+1;k<=n;k++){
				if(a[k]-a[r]<=d) f[k]=f[r]+1,mx=k;
				else break;
			}
		}
	}
	return ;
}
int s[N],g[N];
int count(int l){
	int p,q,sum=0;
	p=q=l;
	for(int i=l;i<=n;i++){
		if(f[i]==(int)1e9) break;
		s[i]+=s[i-1];g[i]+=s[i];
		while(f[p]<=f[i]&&p<=n&&a[p]-a[i]<=d) p++;
		while(f[q]<=f[i]+1&&q<=n&&a[q]-a[i]<=d) q++;
		s[p]+=g[i];s[q]-=g[i];
		if(g[i]==2) sum++;
	}
	return sum;
}
void sol(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++) f[r]=1e9,s[r]=g[r]=0;
		g[l]=1;f[l]=0;
		init(l);
		ans+=count(l);
	}
	cout<<ans<<'\n';
	return ;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=1;
	cin>>c>>t;
	while(t--) sol();
	return 0;
}
//16:23:32 想了下，给C留1.5h，给D留0.5h吧
//看一下C,D能拿多少暴力分
//先看C想一下30min
//16:27:40 konw n^3 28
//16:35:33 might n^2
//16:41:07 yes n^2 40
//17:25:45 n^2 写完了。还有一小时，中午没睡。脑袋好难受啊
//special BC know但是我不想写了
//干他！！！！
//哎呀，原来是我想假了
//18:21:04 马上结束了，至少我能去NOIP了！！！新的赛季，努力训练