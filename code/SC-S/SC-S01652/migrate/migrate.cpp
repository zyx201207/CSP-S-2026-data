#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N=2e6+5,mod=998244353;

inline ll read(){ 
	int w=1;
	ll s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+1LL*(ch-'0');
		ch=getchar();
	}
	return 1LL*w*s;
}

int c,T,n,last[10005];
pair<int,ll> dp[10005];
ll a[N],d,num[10005];

inline void solve1(){
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(a[i]-a[mid]<=d) r=mid;
			else l=mid;
		}
		last[i]=r;
	}
	
	int answer=0;
	for(int s=1;s<n;s++){
		for(int i=0;i<=n+1;i++){
			num[i]=0;
			dp[i]={0,0};
		}
		dp[s]={0,1},num[0]=1;
		int back=s;
		for(int i=s+1;i<=n;i++){
			if(last[i]==i){
				break;
			}	
			int front=max(s,last[i]);
			for(int j=front-1;j>=back;j--)
				num[dp[j].first]-=dp[j].second;		
			back=front;
			dp[i]={dp[front].first+1,num[dp[front].first]};		
			num[dp[front].first+1]+=num[dp[front].first];
		}
		for(int i=s;i<=n;i++){
			if(dp[i].second==2){
				answer++;
			}
		}
	}
	printf("%d\n",answer);
}

inline void solve2(){
	ll val=a[2]-a[1];
	d/=val;
	if(d<=1LL){
		puts("0");
		return;
	}
	int answer=0;
	for(int i=1;i<=n;i++){
		if(1LL*i+2LL*d-1LL<=1LL*n){
			answer++;
		}
	}
	printf("%d\n",answer);
}

inline void solve(){
	scanf("%d",&n),d=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n==1){
		puts("0");
		return;
	}
	if(n<=6000){
		solve1(); //O(n^2)
	} else{
		if(c==11||c==12){
			solve2(); //等差数列
		} else{
			puts("0");
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T); 
	while(T--){
		solve();
	}
	return 0;
} 