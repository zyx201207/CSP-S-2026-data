#include<bits/stdc++.h>
using namespace std;
const int N=6e3+9;
int n,t,c,cnt;
long long x[N],d;
int dis[N][N],nxt[N],head,tail,pre[N],zx;
long long fn[N][N],sum[N];
//vector<vector<int> >mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		//cout<<1;
	    scanf("%d %lld",&n,&d);
	    for(int i=1;i<=n;i++){
	    	nxt[i]=pre[i]=0;
	    	for(int j=i+1;j<=n;j++){
	    		//dis[i][j]=1e9;
	    		fn[i][j]=0;
			}
		}//cout<<2;
	    head=1;
	    //tail=0;
	    cnt=0;
	    for(int i=1;i<=n;i++){
	    	//cout<<i<<' ';
	    	scanf("%lld",&x[i]);
		//	q[tail++]=i;
			//cnt++;
		}//cout<<4;
		for(int i=1;i<=n;i++){
			for(int j=i;j;j--){
				if(x[i]-x[j]<=d)pre[i]=j;
				else break ;
			}
		}
		for(int i=1;i<=n;i++){
			head=i+1;
			for(int j=1;j<=n;j++){
				sum[j]=0;//cout<<6;
			}int pos=0;
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				//cout<<i<<' '<<j;
				dis[i][j]=1;//cout<<7;
				fn[i][j]=1;
				//q[tail++]=j;
				//cnt++;
				pos=j;
				sum[1]++;
			}
			for(int j=pos+1;j<=n;j++){
			  //  cout<<8;
			  if(x[j]-x[j-1]>d){
					break;
				}
				while(head<j&&pre[j]>head){
				//cout<<9;
			//	printf("\n%d %d\n",q[head],dis[i][q[head]]);
		//	cout<<pre[j]<<'$'<<head<<endl;
					sum[dis[i][head]]-=fn[i][head];
					head++;
					//cnt--;
					//cout<<endl<<j<<' '<<q[head]<<' '<<fn[i][q[head]]<<endl;
				}
			//	cout<<sum[dis[i][head]]<<'*'<<head<<'*';
				//cout<<dis[i][head]<<endl;
				//cout<<10;
				dis[i][j]=dis[i][head]+1;
				fn[i][j]=sum[dis[i][head]];
				sum[dis[i][j]]+=fn[i][j];
			}
		}
		long long ans=0;//cout<<11;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(fn[i][j]==2)ans++;
			//	cout<<i<<' '<<j<<':'<<fn[i][j]<<' '<<dis[i][j]<<endl;
			}
		}
		printf("%lld\n",ans);
		//cout<<"\n\n";
	}
	
	return 0;
}