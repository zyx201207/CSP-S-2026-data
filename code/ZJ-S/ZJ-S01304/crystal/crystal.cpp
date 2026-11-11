#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N];
queue<long long> q;
long long ans,sum,cnt,temp;
long long read(){
	char ch=getchar();
	long long dat=0,t=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	n=read(),m=read();
	for(long long i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		while(!q.empty() && a[i]*cnt-sum>m){
			sum-=q.front();
			cnt--;
			q.pop();
		}
		q.push(a[i]);
		cnt++;
		sum+=a[i];
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
