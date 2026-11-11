#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long _1=0;bool _2=0;char _3=getchar();
	while(_3<'0'||_3>'9'){
		if(_3=='-') _2=1;
		_3=getchar();
	}while(_3>='0'&&_3<='9')
		_1=(_1<<3)+(_1<<1)+(_3-48),_3=getchar();
	return (_2?-_1:_1);
}
const int N=2e6+5;
long long a[N];int cnt[N];
queue<int>q[2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read(),n;long long d;
	while(T--){
		n=read(),d=read();
		bool isA=1;long long dif;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>2) isA&=((a[i]-a[i-1])==dif);
			else if(i==2) dif=a[i]-a[i-1];
		}
		if(n>1&&isA){ cout<<max(0LL,(d<dif?0LL:n-d/dif*2+1))<<'\n';continue; }
		if(a[n]-a[1]<=d){ cout<<"0\n";continue; }
		long long ans=0;
		for(int i=1;i<=n;i++){
			int now=0,c0=1,c1=0;
			while(!q[0].empty()) q[0].pop();
			while(!q[1].empty()) q[1].pop();
			q[0].push(i),cnt[i]=1;
			for(int j=i+1;j<=n;j++){
				while(!q[now].empty()&&a[q[now].front()]<a[j]-d) c0-=cnt[q[now].front()],q[now].pop();
				if(q[now].empty()){
					now^=1,swap(c0,c1);
					while(!q[now].empty()&&a[q[now].front()]<a[j]-d) c0-=cnt[q[now].front()],q[now].pop();
				}
				if(c0==2) ans++;
				q[now^1].push(j),cnt[j]=c0,c1+=c0;
			}
		}cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}