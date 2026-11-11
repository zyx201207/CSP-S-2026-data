#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N],ans[N],vis[N];
void dealt(int x,int y,int s[]){
	for(int i=x;i<=y;i++){
		swap(s[x],s[y+i]);
	}
}
void play(int l,int pai){
	if(l==1){
		ans[pai]++;
	}
	vis[pai]++;
	if(vis[pai]>1){
		vis[pai]--;
		for(int i=1;i<=l;i++){
			if(a[i+1]==pai){
				l=i;
			}
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int l=0;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			b[i]=a[j];
			l++;
		}
		play(l,b[1]);
	}
	return 0;
}