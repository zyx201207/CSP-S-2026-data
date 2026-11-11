#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxx=0,maxa=0;
int n,m;
int a[200005];
int b[200005];
int c[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(!b[a[j]])b[a[j]]=1;
			else{
				for(int k=a[j];k<=n;k++){
					b[k]=0;
				}
				b[a[j]]=1;
			}
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]])c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<c[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
