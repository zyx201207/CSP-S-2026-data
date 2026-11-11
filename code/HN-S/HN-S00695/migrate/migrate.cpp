#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long X[N],f[N][3];
int l[N],r[N];
long long dfs(int x,int cnt){
	if(f[x][cnt]!=-1) return f[x][cnt];
	//cout<<x<<' '<<cnt<<endl;
	int xx=x,ccnt=cnt;
	int sum=0;
	int y=r[x];
	if(x==y) return 0;
	if(cnt==1){
		int yy1=r[x-1];
		if(yy1==y){
			cnt++;			
			int yy2=r[x-2];
			if(yy2==y){
				return 0;
			}
			else{
				sum=sum+(y-yy2);
			}			
		}
		else{
			if(yy1!=x){
				int yy2;			
				yy2=r[x-2];	
				sum=sum+yy1-yy2;
			}
		}
	}
	else{
		int yy1=r[x-1];
		if(yy1<y){
			sum=sum+y-yy1;
		}
		else{
			return 0;
		}
	}
	//cout<<y<<endl;
	f[xx][ccnt]=sum+dfs(y,cnt);
	//cout<<xx<<' '<<ccnt<<' '<<f[xx][ccnt]<<endl;
	return f[xx][ccnt];
}
int solve(int st){
	int x=st;
	if(x==r[x]) return 0;
	if(x+1==r[x]) x=r[x];
	if(x==r[x]) return 0;
	x=r[x];
	//cout<<st<<' '<<x<<endl;
	return dfs(x,1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<'1'<<endl;
	int c,T;
	cin>>c>>T;
	while(T--){
		//cout<<"T = "<<T<<endl;
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			f[i][1]=f[i][2]=-1;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&X[i]);
		}
		for(int i=1;i<=n;i++){
			r[i]=upper_bound(X+1,X+n+1,X[i]+d)-X-1;
			//cout<<r[i]<<endl;
		}
		//cout<<r[n]<<endl;
		long long ans=0;
		for(int i=n;i>=1;i--){
			ans=ans+solve(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}