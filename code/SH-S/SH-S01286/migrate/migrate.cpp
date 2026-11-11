#include<bits/stdc++.h>
using namespace std;
long long x[2000005],p[2000005],s1[2000005],s2[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long tt=1;tt<=t;tt++){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		long long n,d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)	cin>>x[i];
		long long l=1,r=1;
		while(l<=n){
			while(x[r]<=x[l]+d && r<=n)	r++;
			r--;
			p[l]=r-l;
			if(p[l]==1)	s1[l]=s1[l-1]+1;
			l++;	
		}
		for(long long i=n;i>=3;i--){
			if(x[i]-d<=x[i-1] and x[i]-d>x[i-2])	s2[i]=s2[i+1]+1;
		}
		s2[2]=s2[3]+1;
		for(long long i=1;i<=n;i++){
			if(p[i]<=1)	continue;
			long long temp=p[i+p[i]-1]+1-p[i+p[i]-2];
			if(temp==0)	continue;
			temp=(temp-1)*(s1[i-1]+1)+(s1[i-1]+1)*(s2[i+p[i]-1+p[i+p[i]-1]+1]+1);
			ans+=temp;
		}
		cout<<ans<<endl;
	} 
	return 0;
}

