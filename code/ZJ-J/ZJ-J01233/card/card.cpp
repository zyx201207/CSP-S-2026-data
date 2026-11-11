#include<bits/stdc++.h>
using namespace std;
int n,m,f[300005],a[500005],cnt[300005],t[500005],now;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		now=0;
		memset(f,-1,sizeof(f));
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			//if(i<10)cout<<i<<','<<j<<" table:";for(int i=1;i<=now;i++)cout<<t[i]<<' ';
			//if(i<10)for(int i=now+1;i<=n;i++)cout<<" ";cout<<"| "<<now<<" cards\n";
			//if(i==2&&f[75]!=-1){for(int i=1;i<=m;i++)cout<<"f["<<i<<"]="<<f[i]<<' ';cout<<'\n';}
			if(f[a[j]]==-1||f[a[j]]>now){
				if(t[now+1]!=0&&f[t[now+1]]>now)f[t[now+1]]=-1;
				f[a[j]]=++now;
				t[now]=a[j];
			}else{
				now=f[a[j]];
			}
		}
		for(int i=1;i<=now;i++)cnt[t[i]]++;
		//if(i<10)cout<<"table:";for(int i=1;i<=now;i++)cout<<t[i]<<' ';
		//if(i<10)for(int i=now+1;i<=n;i++)cout<<" ";cout<<"| "<<now<<" cards\n\n";
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}