#include<iostream>
#include<algorithm>
#define N 4000010
#define INF 1145141919810000
using namespace std;
long long n,d,a[N],r[N],l[N],dp[N],cnt[N],cnt2[N],ans;
long long solve(long long x,long long y){
	if(y-x+1<=3){
		return 0;
	}
	long long sum=0;
	cnt[y+1]=0;
	cnt[y]=1;
	for(int i=y-1;i>=x;--i){
		cnt[i]=1;
		if(r[i]==i+1&&l[i+1]==i){
			cnt[i]+=cnt[i+1];
		}
	}
	dp[y+1]=0;
	l[y+1]=-1;
	for(int i=y;i>=x;--i){
		dp[i]=0;
		if(r[i]==i+1&&l[i+1]==i){
			dp[i]+=dp[i+1];
		}
		long long tk=r[i],tk2=r[tk];
		if(i==tk||i+1==tk||tk==tk2){
			continue;
		}
		if(tk==tk2-1){
			if(l[tk2]==tk-1){
				dp[i]+=cnt[tk2];
			}
			continue;
		}
		long long ll=tk+1,rr=tk2,anss=-1;
		while(ll<=rr){
			long long mid=(ll+rr)>>1;
			if(l[mid]>tk-1){
				rr=mid-1;
			}
			else if(l[mid]==tk-1){
				anss=mid;
				rr=mid-1;
			}
			else{
				ll=mid+1;
			}
		}
		long long tt=anss;
		ll=tk+1,rr=tk2,anss=-1;
		while(ll<=rr){
			long long mid=(ll+rr+1)>>1;
			if(l[mid]<tk-1){
				ll=mid+1;
			}
			else if(l[mid]==tk-1){
				anss=mid;
				ll=mid+1;
			}
			else{
				rr=mid-1;
			}
		}
		if(anss==-1||tt==-1){
			continue;
		}
//		cout<<anss<<" "<<tt<<endl; 
		dp[i]+=anss-tt+cnt[anss];
	}
	for(int i=x;i<=y;++i){
		sum+=dp[i];
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		long long tk=1;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			while(a[i]-a[tk]>d){
				r[tk]=i-1;
				++tk;
			}
		}
		while(tk<=n){
			r[tk]=n;
			++tk;
		}
		tk=n;
		for(int i=n;i>=1;--i){
			while(a[tk]-a[i]>d){
				l[tk]=i+1;
				--tk;
			}
		}
		while(tk>=1){
			l[tk]=1;
			--tk;
		}
		tk=1;
		for(int i=1;i<=n;++i){
			if(l[i]==i){
				ans+=solve(tk,i-1);
				tk=i;
			}
		}
		cout<<ans+solve(tk,n)<<endl;
	}
	return 0;
}
/*
500 ->10000 s bian
20*500*500
*/
