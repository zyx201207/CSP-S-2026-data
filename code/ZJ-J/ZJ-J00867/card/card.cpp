#include <bits/stdc++.h>
using namespace std;
long long n,m,c,b[500100],a[500100],k,ans[300100],d[500100];
long long yl(long long x,long long y){
	for(int i=1;i<=y;i++){
		if(b[i]==x){
			return i;
		}
	}
	return 0;
}
void lmqakioi(){
	for(int i=k;i<=c;i++){
		b[i]=-1;
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c=0;
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){
			k=yl(a[j],c);
			if(k!=0){
				lmqakioi();
				c++;
				b[c]=a[j];
			}
			else{
				c++;
				b[c]=a[j];
			}
		}
//		for(int i=1;i<=c;i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<'\n';
		for(int j=1;j<=c;j++){
			if(d[b[j]]==0){
				ans[b[j]]++;
				d[b[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
