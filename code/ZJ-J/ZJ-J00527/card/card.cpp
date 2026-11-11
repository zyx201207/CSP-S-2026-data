#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int n,m,a[500005],t[300005];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(q.front()!=a[j])q.push(a[j]);
			while(!q.empty()){
				t[q.front()]++;
				q.pop();
			}
		}
	for(int i=1;i<=m;i++)printf("%d ",t[i]);
	return 0;
}
