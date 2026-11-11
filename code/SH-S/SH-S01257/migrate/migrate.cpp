#include<bits/stdc++.h>
using namespace std;
const int N=2.1e6;
int c,t,n;
long long d,x[N];
void file(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
void input(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
}
namespace sub1_2{
	int mn[10][10],cps[10],cnt[10][10];
	void func(){
		int ans=0;
		memset(mn,0x3f,sizeof(mn));
		memset(cnt,0,sizeof(cnt));
		for(int st=0;st<(1<<n);st++){
			int len=0;
			for(int i=0;i<n;i++){
				if((1<<i)&st){
					cps[++len]=i+1;
				}
			}
			if(len>mn[cps[1]][cps[len]] or len<2)continue;
			bool flag=true;
			for(int i=1;i<len and flag;i++){
				if(x[cps[i+1]]-x[cps[i]]>d)flag=false;
			}
			if(flag){
				//printf("<%d %d %d>",cps[1],cps[len],len);
				if(len==mn[cps[1]][cps[len]])cnt[cps[1]][cps[len]]++;
				else mn[cps[1]][cps[len]]=len,cnt[cps[1]][cps[len]]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//printf("<%d %d %d>",i,j,cnt[i][j]);
				if(cnt[i][j]==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
}
namespace sub3_6{
	int f[310][310],cnt[310][310];
	void func(){
		int ans=0;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)f[i][i]=1,cnt[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					if(x[j]-x[k]<=d){
						if(f[i][j]==f[i][k]+1){
							cnt[i][j]+=cnt[i][k];
						}
						else if(f[i][j]>f[i][k]+1){
							cnt[i][j]=cnt[i][k];
							f[i][j]=f[i][k]+1;
						}
					}
				}
				if(cnt[i][j]==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
}
namespace sub7_10{
	int f[5100][5100],cnt[5100][5100],q[5100];
	void func(){
		int ans=0;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)f[i][i]=1,cnt[i][i]=1;
		for(int i=1,l,r,mxcnt;i<=n;i++){
			l=1,r=1,q[1]=i,mxcnt=1;
			for(int j=i+1;j<=n;j++){
				while(l<=r and x[j]-x[q[l]]>d){
					if(l==r)mxcnt=0;
					else if(f[i][q[l]]!=f[i][q[l+1]]){
						mxcnt=0;
						for(int j=l+1;j<=r and f[i][q[l+1]]==f[i][q[j]];j++)mxcnt+=cnt[i][q[j]];
					}
					else mxcnt-=cnt[i][q[l]];
					l++;
				}
				//printf("{%d %d %d}",(l<=r)?q[l]:-1,(l<=r)?f[i][q[l]]:-1,(l<=r)?mxcnt:-1);
				if(l<=r){
					f[i][j]=f[i][q[l]]+1,cnt[i][j]=mxcnt;
				}
				if(cnt[i][j]==2)ans++;
				while(l<=r and f[i][q[r]]>f[i][j])r--;
				if(l>r)mxcnt=0;
				q[++r]=j;
				if(f[i][j]==f[i][q[l]])mxcnt+=cnt[i][j];
				
				//printf("<%d %d %d>",(l<=r)?q[l]:-1,(l<=r)?f[i][q[l]]:-1,(l<=r)?mxcnt:-1);
			}
			//printf("\n");
		}
		printf("%d\n",ans);
	}
}
namespace subA{
	void func(){
		long long delta=x[2]-x[1],t=d/delta;
		if(t==0 or t==1 or n<2*t){
			printf("0\n");
			return;
		}
		printf("%lld\n",n-2*t+1);
	}
}
int main(){
	file();
	scanf("%d%d",&c,&t);
	while(t--){
		input();
		if(n<=9)sub1_2::func();
		else if(n<=300)sub3_6::func();
		else if(n<=5000)sub7_10::func();
		else if(c==11 or c==12)subA::func();
	}
	return 0; 
}
