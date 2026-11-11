#include<bits/stdc++.h>
using namespace std;
int n,m,v[500005],a[500005],s[500005];
struct po{
	int x,y;
}q[500005];
int main(){ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		memset(v,0,sizeof(v));
		int len=0;
		memset(q,0,sizeof(q));
		for(int i=j;i<=n;i++){
			if(!v[a[i]]){
				len++;
				v[a[i]]=len;
				q[len].x=a[i];
				q[len].y=i;
			}
			else{
				for(int k=v[a[i]]+1;k<=len;k++)v[a[q[k].y]]=0;
				len=v[a[i]];
			}
		}for(int i=1;i<=len;i++)s[q[i].x]++;
	}for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}