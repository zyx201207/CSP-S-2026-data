#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],cnt[M],nt[M];
bool st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		memset(nt,0,sizeof nt);
		memset(st,0,sizeof st);
		for(int j=i+1;j<=n;j++){
			if(!nt[a[j]]){cnt[a[j]]++;nt[a[j]]=j;}
			else{
				for(int p=nt[a[j]];p<j;p++){
					if(!st[p]){cnt[a[p]]--;nt[a[p]]=0;}
					st[p]=1;
				}
				cnt[a[j]]++;
				nt[a[j]]=j;
			}
		}
		//for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
		//puts("");
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}
