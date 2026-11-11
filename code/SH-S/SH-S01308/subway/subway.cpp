#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=50005;
const int maxn=505;
const int maxd=22;
int num,suball,stageall,maxroad,plannum;//c,n,m,d,q
int goin[maxm];
int ans=-1;
bool got[maxn];
bool wented[maxm];
int a[maxn][maxm];
int t[maxn][maxm];
void dfs(int s,int e,int now,int time,int sub,int out){
	if(now==e){
		if(ans==-1)ans=time+out;
		else ans=min(ans,time+out);
		return;
	}
	for(int i=1;i<=suball;i++){
		if(!got[i]){
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]==now){
					int newtime=0;
					if(now==s)newtime=t[i][j];
					else newtime=time+out+t[i][j];
					got[i]=true;
					for(int k=j;k<=a[i][0];k++){
//						if(!wented[a[i][k]]){
							wented[a[i][k]]=true;
							dfs(s,e,a[i][k],newtime,i,t[i][k]);
							wented[a[i][k]]=false;
//						}
					}
					got[i]=false;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>num>>suball>>stageall>>maxroad>>plannum;
	for(int i=1;i<=stageall;i++)cin>>goin[i];
	for(int i=1;i<=suball;i++){
		cin>>a[i][0];//×Ü¼ÆÕ¾Êý 
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=plannum;i++){
		int s,e;
		cin>>s>>e;
		dfs(s,e,s,0,0,0);
		if(ans!=-1) cout<<ans+goin[s]+goin[e]<<"\n";
		else cout<<goin[s]+goin[e]<<"\n";
		ans=-1;
	}
	return 0;
} 
