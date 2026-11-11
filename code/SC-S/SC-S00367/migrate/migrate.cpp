#include<bits/stdc++.h>
using namespace std;
int C,T,n,dp1[2000010],dp2[2000010],nxt[2000010],lst[2000010],cntl[2000010],cntr[2000010];
long long X[2000010],D,ans,s[2000010],cnt; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	if(C<=10){
		while(T--){
			cin>>n>>D;
			for(register int i=1;i<=n;++i)
				cin>>X[i];
			ans=0;
			for(register int f=1;f<=n;++f){
				dp1[f]=0;dp2[f]=1;
				for(register int i=f+1,l=f,r=f;i<=n;++i){
					dp1[i]=1e9;
					while(D<X[i]-X[l])
						++l;
					while(r+1<i&&(r<l||dp1[r+1]==dp1[l]))
						++r;
					if(r<l)
						break;
					dp1[i]=dp1[l]+1;
					if(2<r-l)
						dp2[i]=3;
					else{
						dp2[i]=0;
						for(register int j=l;j<=r;++j)
							dp2[i]=min(dp2[i]+dp2[j],3);
					}
					if(dp2[i]==2)
						++ans;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else if(C<=12){
		while(T--){
			cin>>n>>D;
			for(register int i=1;i<=n;++i)
				cin>>X[i];
			ans=0;
			dp1[1]=0;dp2[1]=1;
			for(register int i=2,l=1,r=1;i<=n;++i){
				dp1[i]=1e9;
				while(D<X[i]-X[l])
					++l;
				while(r+1<i&&(r<l||dp1[r+1]==dp1[l]))
					++r;
				if(r<l)
					break;
				dp1[i]=dp1[l]+1;
				if(2<r-l)
					dp2[i]=3;
				else{
					dp2[i]=0;
					for(register int j=l;j<=r;++j)
						dp2[i]=min(dp2[i]+dp2[j],3);
				}
				if(dp2[i]==2)
					ans+=n+1-i;
			}
			cout<<ans<<'\n';
		}
	}
	else{
		while(T--){
			cin>>n>>D;
			for(register int i=1;i<=n;++i)
				cin>>X[i];
			for(register int i=1,j=1;i<=n;++i){
				while(j<n&&X[j+1]-X[i]<=D)
					++j;
				nxt[i]=j;
			}
			for(register int i=n,j=n;i;--i){
				while(1<j&&X[i]-X[j-1]<=D)
					--j;
				lst[i]=j;
			}
			cntl[1]=s[1]=1;
			for(register int i=2;i<=n;++i){
				if(i==lst[i]){
					cntl[i]=1;
					s[i]=s[i-1]+1;
					continue;
				}
				register int x=lst[i];
				cntl[i]=i-x+1;
				cntl[i]+=s[lst[x+1]-1]-s[lst[x]-1];
				s[i]=s[i-1]+cntl[i];
			}
			s[n]=cntr[n]=1;
			for(register int i=n-1;i;--i){
				if(i==nxt[i]){
					cntr[i]=1;
					s[i]=s[i+1]+1;
					continue;
				}
				register int x=nxt[i];
				cntr[i]=x-i+1;
				cntr[i]+=s[nxt[x-1]+1]-s[nxt[x]+1];
				s[i]=s[i+1]+cntr[i];
			}
			ans=cnt=0;
			for(register int i=1;i<=n;++i){
				if(i+1<nxt[i]){
					register int x=nxt[nxt[i]];
					register int r=nxt[x],l=nxt[x-1];
					x=nxt[nxt[i]-1];
					r=min(r,nxt[x]);
					l=max(l,nxt[x-1]);
					if(l<=r)
						ans+=cntl[i]*(s[l+1]-s[r+1]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
