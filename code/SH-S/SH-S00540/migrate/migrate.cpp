#include<bits/stdc++.h>
using namespace std;
#define N 2000005
typedef long long LL;
int c,T,n,pre[N],nxt[N];
LL d,x[N];
LL dp[N],dis[N],ed[N],s[N];
LL ans;
void init(){
	int l=1;
	pre[1]=0;
	for(int r=2;r<=n;r++){
		while(x[r]-x[l]>d){l++;}
		pre[r]=l;
	}
}
void init2(){
	int r=n;
	nxt[n]=n+1;
	for(int l=n-1;l>=1;l--){
		while(x[r]-x[l]>d){r--;}
		nxt[l]=r;
	}
}
void play(int st){
	dis[st]=0;
	ed[dis[st]]=st;
	for(int i=st+1;i<=n;i++){
		if(pre[i]==i){break;}
		dis[i]=dis[pre[i]]+1;
		ed[dis[i]]=i;
	}
	dp[st]=1;
	s[st-1]=0,s[st]=dp[st];
	for(int i=st+1;i<=n;i++){
		if(pre[i]==i){break;}
		int d=dis[pre[i]];
		dp[i]=min(s[ed[d]]-s[pre[i]-1],3ll);
		s[i]=s[i-1]+dp[i];
	}
	for(int i=st;i<=n;i++){
		ans+=(dp[i]==2);
	}
}
void taskA(){
	LL a=x[2]-x[1],b=d/a;
	if(d<a){
		ans=0;}
	else{
		ans=max(0ll,n-2*b+1);}		
}
void taskB(){
	int mid=1;
	LL ct1=0,ct2=0,ct3=0,ct4=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){mid=i;break;}
	}
	init(),init2();
	for(int i=1;i<mid;i++){
		if(nxt[i]==mid+1)ct1++;
		if(nxt[i]==mid)ct3++;
	}
	for(int i=mid+1;i<=n;i++){
		if(pre[i]==mid-1)ct2++;
		if(pre[i]==mid)ct4++;
	}
	ans=ct1*ct4+ct2*ct3;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(11<=c&&c<=12){
			taskA();
		}
		else if(13<=c&&c<=14){
			taskB();
		}
		else{
			init();
			for(int i=1;i<=n;i++){
				play(i);
			}	
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
