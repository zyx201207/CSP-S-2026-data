#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int N=2e6+9;
ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1ll;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int c,T,cnt,ans,_min,a[N],d,n;
bool ok[15];
void check(int l,int r){
//	for(int i=l;i<=r;i++) cout<<ok[i]<<' ';
//	cout<<endl;
	int sum=0,lst=l;
	for(int i=l+1;i<=r;i++){
		if(ok[i]){
			if(a[i]-a[lst]>d) return;
			sum++;
			lst=i;
		}
	}
	if(sum<_min){
		cnt=1;
		_min=sum;
	}
	else if(sum==_min){
		cnt++;
	}
//	cout<<"sum:"<<sum<<"_min:"<<_min<<endl;
}
void dfs(int now,int l,int r){
//	cout<<now<<endl;
	if(now==r){
		ok[now]=1;
		check(l,r);
		ok[now]=0;
	}
	else if(now==l){
		ok[now]=1;
		dfs(now+1,l,r);
		ok[now]=0;
	}
	else{
		ok[now]=1;
		dfs(now+1,l,r);
		ok[now]=0;
		dfs(now+1,l,r);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0,_min=0x3f3f3f3f;
				dfs(i,i,j);
//				cout<<cnt<<endl;
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

