#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int idq[200005];
int q[200005];
int cnt[200005];
int zcnt[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(idq,-1,sizeof(idq));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0;
		memset(cnt,0,sizeof(cnt));
		memset(q,0,sizeof(q));
		memset(idq,-1,sizeof(idq));
		for(int j=i;j<=n;j++){
			if(idq[a[j]]!=-1&&q[idq[a[j]]]!=-1){
				for(int z=idq[a[j]];z<=l;z++){
					q[z]=-1;
				}
				q[++l]=a[j];
				idq[a[j]]=j;
			}else{
				idq[a[j]]=j;
				q[++l]=a[j];
			}
		}
		for(int t=1;t<=l;t++){
			if(q[t]!=-1){
				cnt[q[t]]++;
			}
		}
		for(int t=1;t<=m;t++){
			zcnt[t]+=cnt[t];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zcnt[i]<<' ';
	}
	return 0;
}
