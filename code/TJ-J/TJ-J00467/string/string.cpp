#include<iostream>
#define int long long
using namespace std;
int n;
struct num{
	int id;
	int cnt;
	char c;
}a[200005];
int s[200005];
int mxcnt=0;
int L;
int qury(int x){
	int l=s[x-1]+1;int r=s[x];
	int rr=L-l+1;int rl=L-r+1;
	num rq;
	num lq;
	for(int i=x;i<=n;i++){
		int tl=s[i-1]+1;int tr=s[i];
		if(rr>=tl&&rr<=tr){
			rq=a[i];
		}
		if(rl>=tl&&rl<=tr){
			lq=a[i];
		}
	}
	if(lq.id==rq.id){
		if(lq.c!=a[x].c){
			return abs(rr-rl+1);
		}
		else return 0;
	}
	else{
		int ctn=0;
		if(lq.c!=a[x].c){
			ctn+=abs(s[lq.id]-rl+1);
		}
		if(rq.c!=a[x].c){
			ctn+=abs(rr-(s[rq.id-1]+1)+1);
		}
		return ctn;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		a[i].id=i;
		mxcnt=max(mxcnt,a[i].cnt);
		L+=a[i].cnt;
		s[i]=s[i-1]+a[i].cnt;
	}
	if(mxcnt<=50){
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].cnt;j++){
				s+=a[i].c;
			}
		}
		s=" "+s;
		int ans=0;
		L=s.size()-1;
		for(int i=1;i<=L/2;i++){
			if(s[i]!=s[L-i+1]){
				ans++;
			}
		}
		cout<<ans;
	}
	else if(n<200000){
		int ans=0;
		int ed=0;
		for(int i=1;s[i]<=L/2;i++){
			ed=i;
			ans+=qury(i);
		}
		if(s[ed]<L/2){
			int lzuobian=s[ed]+1;
			int ryoubian=L-lzuobian+1;
			for(int i=ed+1;i<=n;i++){
				if(s[i-1]+1>=ryoubian&&s[i]<=ryoubian){
					int qujianzuobian=s[i-1]+1;
					if(a[i].c!=a[ed+1].c){
						ans+=ryoubian-qujianzuobian+1;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
