#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=2e6+7;
int C,T=1;
int n;
long long x[MAXN],d;
inline void Read(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
}
pair<int,int> Queue[MAXN];
int head,tail=1;
int cnt[MAXN];
int f[MAXN];
bool check1(){
	long long d=x[2]-x[1];
	for(int i=3;i<=n;i++)
		if(x[i]-x[i-1]!=d) return 0;
	return 1;
}
inline void Solve(){
	long long ans=0;
	for(int l=1;l<=n;l++){
		for(int i=0;i<=n;i++)
			cnt[i]=f[i]=0;
		head=0,tail=1;
		Queue[++head]={0,l};
		cnt[0]=f[l]=1;
		for(int r=l+1;r<=n;r++){
			while(tail<=head&&x[Queue[tail].second]<x[r]-d)
				cnt[Queue[tail].first]-=f[Queue[tail].second],tail++;
			if(tail>head) break;
			int w=Queue[tail].first;
			if(cnt[w]==2) ans++;
			f[r]=cnt[w];
			cnt[w+1]+=f[r];
			while(tail<=head&&Queue[head].first>w+1)
				cnt[Queue[head].first]-=f[Queue[head].second],head--;
			Queue[++head]={w+1,r};
		}
	}
	cout<<ans<<"\n";
}
inline void Solve1(){
	if(d==1) cout<<0;
	else cout<<max(0ll,-2*d+n+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		Read();
		if(n>5000&&check1()) Solve1();
		else Solve1();
	}
	
	return 0;
}
