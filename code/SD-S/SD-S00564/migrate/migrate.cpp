#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
	return x*f;
}
int c,t,n,m,a[2000005],fl[2000005],fr[2000005],f1[2000005],f2[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),m=read();
		for(int i=1;i<=n+2;i++) a[i]=fl[i]=fr[i]=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			int l=1,r=i,mid,k=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[i]-a[mid]<=m) r=mid-1,k=mid;
				else l=mid+1;
			}
			fl[i]=k;
			l=i,r=n,mid,k=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[mid]-a[i]<=m) l=mid+1,k=mid;
				else r=mid-1;
			}
			fr[i]=k;
		}
		/*for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<"\n";
		for(int i=1;i<=n;i++) cout<<fl[i]<<" ";
		cout<<"\n";
		for(int i=1;i<=n;i++) cout<<fr[i]<<" ";
		cout<<"\n";*/
		for(int i=1;i<=n;i++) f1[i]=f2[i]=1;
		for(int i=n;i>=1;i--) if(fl[i]!=i){
			//if(fl[fl[i]+1]>fl[fl[i]])  f2[fl[i]]+=f2[i];
			if(fl[fl[i]+1]>fl[i]) f2[fl[i]]+=f2[i];
		}
		for(int i=1;i<=n;i++) if(fr[i]!=i){
			//if(fr[fr[i]-1]<fr[fr[i]]) f1[fr[i]]+=f1[i];
			if(fr[fr[i]-1]<fr[i]) f1[fr[i]]+=f1[i];
		}
		/*cout<<"\n";
		for(int i=1;i<=n;i++) cout<<f1[i]<<" ";
		cout<<"\n";
		for(int i=1;i<=n;i++) cout<<f2[i]<<" ";
		cout<<"\n";*/
		int sum=0;
		for(int i=1;i<=n;i++){
			if(fr[i]<i+2) continue;
			int l=fr[fr[i]-2]+1,r=fr[fr[i]-1];
			//cout<<i<<" "<<l<<" "<<r<<"\n";
			if(l>r) continue;
			//int ll=f2[fr[fr[i]]+1],rr=f1[fl[fl[r]]-1];
			int ll=f1[i],rr=f2[r];
			sum+=f1[i]*(r-l)+ll*rr;
			//cout<<sum<<"\n";
		}
		printf("%lld\n",sum);
		//cout<<"\n";
	}
	return 0;
}
/*
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
*/
