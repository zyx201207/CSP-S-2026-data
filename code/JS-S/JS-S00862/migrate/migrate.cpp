#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int s[N],n,d,l[N],r[N],numl[N],numr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>s[i];
		if(n<=3){cout<<0<<'\n';continue;}
		if(C==11 || C==12){
			int len=d/(s[2]-s[1]);
			if(len<=1)cout<<0<<'\n';
			else cout<<n-len-1<<'\n';
			continue;
		}
		if(C==13 || C==14){
			int p[n+2],rr[n+2],ans=0;
			memset(p,0,sizeof(p));
			memset(rr,0,sizeof(rr));
			for(int i=1,j=1;i<=n;i++){
				while(s[j+1]-s[i]<=d && j<n)j++;
				rr[j]++;p[i]=j;
			}
			for(int i=n,j=n;i>=1;i--){
				while(-s[j-1]+s[i]<=d && j>1)j--;
				ans+=rr[j+1];
				if(p[j]==j+1)ans--;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=n,j=n;i>=1;i--){
			if(j>i)j=i;
			while(j>1 && s[i]-s[j-1]<=d)j--;
			l[i]=j;
			numl[j]++;
		}
		for(int i=1,j=1;i<=n;i++){
			if(j<i)j=i;
			while(j<n && -s[i]+s[j+1]<=d)j++;
			r[i]=j;
			numr[j]++;
		}
		int ans=0;
		for(int i=2;i<=n;i++){
			int L=i+1,R=r[i];
			if(L>R)continue;
			int num=numl[i-1];
			if(l[i]==i-1)num--;
			if(l[i-1]==i-1)num--;
			if(l[R+1]==i-1){
				int nw=R+1;
				for(int i=1<<20;i;i/=2){
					if(l[nw+i]==i-1){
						nw+=i;
					}
				}
				num-=nw-R;
			}
			int ano=numr[i];
			if(r[i]==i)ano--;
			ans+=ano*num;
		}
		for(int i=1;i<=n;i++){
			l[i]=0;r[i]=0;numl[i]=0;numr[i]=0;s[i]=0;
		}
		cout<<ans<<'\n';
	}
}
