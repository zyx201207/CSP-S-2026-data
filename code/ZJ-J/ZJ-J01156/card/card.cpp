#include<bits/stdc++.h>
using namespace std;
int a[500005];
int x[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof x);
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0)x[a[j]]=j;
			else{
				for(int w=1;w<=m;w++){
					if(x[w]>x[a[j]])x[w]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)if(x[j]!=0)b[j]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}