#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000009],d[2000009];
long long read(){
	long long ret=0,ty=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ty=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		ret=ret*10+c-'0',c=getchar();
	return ret*ty;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		bool flag=1;
		n=read(),m=read();
		for(long long i=1;i<=n;i++)
			a[i]=read();
		for(long long i=1;i<n;i++)
			d[i]=a[i+1]-a[i],flag&=(i==1||d[i]==d[i-1]);
		if(flag){
			long long tmp=m/d[1];
			if(tmp<=1)
				cout<<"0\n";
			else
				cout<<max(0ll,n-2*tmp+1)<<"\n";
			continue;
		}
		n--;
		long long ans=0;
		for(long long i=1;i<n;i++)
			for(long long j=i+1;j<=n;j++){
				vector<long long> lst,len;
				long long sum=0;
				flag=0;
				for(long long k=i;k<=j;k++){
					if(d[k]>m){
						flag=1;
						break;
					}
					if(sum+d[k]>m){
						lst.push_back(k-1),len.push_back(sum);
						sum=0;
					}
					sum+=d[k];
				}
				if(flag)
					continue;
				lst.push_back(j),len.push_back(sum);
				long long cnt=0;
				for(long long i=1;i<lst.size();i++){
					long long rlst=0,rlen=0;
					while(cnt<2&&len[i]+d[lst[i-1]]<=m){
						cnt++;
						if(cnt==1&&i>1)
							if(len[i-1]-d[lst[i-1]]+d[lst[i-2]]<=m)
								cnt++;
						lst[i-1]--,len[i]+=d[lst[i-1]+1],rlst++,rlen-=d[lst[i-1]+1];
					}
					lst[i-1]+=rlst,len[i]+=rlen;
				}
				ans+=(cnt==1);
			}
		cout<<ans<<"\n";
	}
	return 0;
} 
