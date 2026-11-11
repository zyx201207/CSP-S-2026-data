#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N];
int n,m;
int s[N],tt=0;
int st[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(st,0,sizeof st);
		for(int j=i;j<=n;j++){
			while(st[a[j]]>0){
				st[s[tt--]]--;
			}
			s[++tt]=a[j];
			st[a[j]]++;
		}
		while(tt){
			ans[s[tt--]]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
} 
