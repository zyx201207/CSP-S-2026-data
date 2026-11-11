#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll const N=1e6+10;
ll n,m,a[N],b[N],c,s[N],d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c=0;
	for(int i=1;i<=n;i++){
		d=0;
		for(int j=c;j<=n;j++){
			b[d++]=a[j];
		}c++;
		d-=1;
		for(int j=2;j<=d;j++){
			for(int l=1;l<=j-1;l++){
				if(b[l]==b[j]){
					for(int k=l;k<j;k++)b[k]=0;
				}else continue;
			}
		}
		for(int j=1;j<=d;j++){
			for(int l=1;l<=m;l++){
				if(b[j]==l)s[l]++;
			}
		}
		memset(b,0,sizeof b);
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
