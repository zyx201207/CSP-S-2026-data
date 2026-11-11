#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,maxa,t,k;
bool A=1,B=1,has[4];
void dfs(long long cnt,long long pos,long long ads){
	for(int i=pos+1;i<=n-m+cnt+1;i++){
		if(cnt==m-1)
			ans=max(ans,ads&a[i]);
		else
			dfs(cnt+1,i,ads&a[i]);
	}return;
}bool cmp(int o,int p){
	return o>p;
}long long f(int k,int x){
	return (x<=(1<<(k-1)))?((1<<(k-1))+f(k-1,x)):(0);
}int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin>>n>>m,t=n;
	while(t>1){
		B=B&&(t%2==0);
		t>>=1;
		k++;
	}for(int i=1;i<=n;i++)
		cin>>a[i],maxa=max(a[i],maxa),A=A&&((a[i]&a[i]+1)==0),B=B&&(a[i]==i-1);
	if(m==1)
		ans=maxa;
	else if(m==2)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
	}else if(m==n-1)
		for(int i=1;i<=n;i++){
			t=(a[i%n+1]&a[(i+1)%n+1]);
			for(int j=2;j<n-1;j++)
				t&=a[(i+j)%n+1];
			ans=max(t,ans);
		}
	else if(A){
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)
			ans&=a[i];
	}else if(B)
		ans=f(k,m);
	else if(maxa<4){
		for(int i=1;i<=n;i++)
			has[a[i]]++;
		ans=maxa;
		for(int i=maxa;i>=0&&m>0;i--)
			m-=has[i],ans&=i;
	}else
		for(int i=1;i<=n;i++)
			dfs(1,i,a[i]);
	cout<<ans;
	return 0;
}
