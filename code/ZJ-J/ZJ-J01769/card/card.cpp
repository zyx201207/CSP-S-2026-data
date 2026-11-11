#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],w[300005];
void ru(int &a){
	a=0;char in=getchar();bool zf=0;
	while(in<'0'||in>'9'){if(in=='-')zf=1;in=getchar();}
	while(in>='0'&&in<='9'){a=(a<<1)+(a<<3)+(in^48);in=getchar();}
	if(zf)a=-a;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ru(n);ru(m);
	for(int i=1;i<=n;i++)ru(a[i]);
	if(n<=500){
		for(int i=1;i<=n;i++){
			memset(w,0,sizeof(w));
			for(int j=i,x;j<=n;j++){
				if(w[a[j]]){
					for(int l=w[a[j]];l<=j;l++)
					w[a[l]]=0;
				}
				w[a[j]]=j;
			}
			for(int j=1;j<=m;j++)if(w[j])s[j]++;
		}
		for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=m;j++)s[j]++;
		}
		for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	}
}