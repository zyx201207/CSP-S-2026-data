#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],top,b[N],c[N],d[N],e[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=max(m,n);j++){
			c[j]=0;
			b[j]=-1;
		}
		for(int j=i;j<=n;j++){
			long long x=a[j];
			if(b[x]==-1||b[x]>top||c[b[x]]!=x){
				top++;
				c[top]=x;
				b[x]=top;
			}else{
				top=b[x];
			}
		}
		for(int j=1;j<=m;j++){
			e[j]=0;
		}
		for(int j=1;j<=top;j++){
			if(e[j]==0){
				d[c[j]]++;
				e[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
