#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],c[500001],x;
int s[500001],p[500001];
bool o[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(o,0,sizeof(o));
		memset(s,0,sizeof(s));
		int k=0;
		x=0;
		for(int j=i;j<=n;j++){
			while(o[a[j]]){
				o[s[x]]=0;
				x--;
			}
			s[++x]=a[j];
			o[a[j]]=1;
		}
		for(int j=1;j<=x;j++) p[s[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<p[i]<<" ";
	return 0;
} 
