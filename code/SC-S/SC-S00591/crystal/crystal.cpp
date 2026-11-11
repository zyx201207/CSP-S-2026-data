#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;

int n,m,a[500001],ans=1,maxn;
queue<int> q;
int read(){
	char c;
	int ret=0,f=1;
	c=getchar();
	if(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}return ret*f;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}sort(a+1,a+n+1);
	q.push(1);
	for(int i=2;i<=n;i++){
		maxn+=(a[i]-a[i-1])*q.size();
		while(maxn>m){
			maxn-=a[i]-a[q.front()];
			q.pop();
		}q.push(i);
		ans=max(ans,(int)q.size());
	}cout<<ans;
}