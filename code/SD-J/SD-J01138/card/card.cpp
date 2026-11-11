#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],cnt,c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++){
		memset(b,0,sizeof b);
		cnt=0;
		for(int j=l;j<=n;j++){
			for(int i=1;i<=cnt;i++){if(b[i]==a[j]){cnt=i-1;break;}}
			b[++cnt]=a[j];
		}
		for(int i=1;i<=cnt;i++)c[b[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
