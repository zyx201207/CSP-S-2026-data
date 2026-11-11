#include<bits/stdc++.h>
using namespace std;

const int MAXM=3e5+10,MAXN=5e5+10;

int a[MAXN];          //a[i]:牌堆第i张 
bool work[MAXN];      //work[i]:每次,每张牌的标记
int cnt[MAXM];        //cnt[i]:每张牌的次数
bool vis[MAXM];       //vis[i]:每轮是否用了点数为i的牌

int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(work,0,sizeof work);
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			work[j]=1;
			for(int k=j+1;k<=n;k++) if(a[j]==a[k]){
				work[j]=0,work[k]=1,j=k;
				break;
			}
		}
		for(int j=i;j<=n;j++) if(work[j]) vis[a[j]]=1;
		for(int j=1;j<=m;j++) cnt[j]+=vis[j];
	}
	for(int j=1;j<=m;j++) cout<<cnt[j]<<' ';
	return 0;
}
