#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,a[1000005],ans,q[100000005][2],l,r,geshu;
long long bfs(long long x,long long y){
	bool flag=false;
	memset(q,0,sizeof(q));
	l=r=1;
	long long minstep=9999999999,mark=0,qw=0;
	q[r][0]=x,q[r][1]=0,r++;
	while(l<r){
		long long place=q[l][0],step=q[l][1],next=1;
		if(place==y){
			minstep=min(minstep,step);
			if(flag==false){
				flag=true,mark=l;
			}
			l++;
			continue;
		}
		long long far=a[place]+m;
		if(far>a[y]){
			far=a[y];
		}
		while(far>=a[place+next]&&place+next<=y){
			q[r][0]=place+next,q[r][1]=step++,r++;
			next++;
		}
		l++;
	}
	for(;mark<=r;mark++){
		if(q[mark][1]==minstep){
			qw++;
		}
	}
	return qw;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			geshu=0;
			for(long long j=i+3;j<=n;j++){
				geshu=bfs(i,j);
				if(geshu==2){
					ans++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}