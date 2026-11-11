#include<bits/stdc++.h>
using namespace std;
int p[500005],z[300001],s[300001];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,x,y,i,j,t,l,g=0;
	cin>>n>>m;
	for(x=0;x<n;x++)cin>>p[x];
	for(x=0;x<n;x++){
		for(y=x;y<n;y++){
			z[y]=p[y];
			for(i=y;i>=x;i--){
				if(z[i]==z[y]&&z[i]>0&&z[y]>0)
				for(j=y;j>i;j--)z[j]=0;
			}
		}
		for(t=x;t<n;t++)if(z[t]>0)s[z[t]]+=1;
		for(l=0;l<=n;l++)z[l]=0;
	}
	for(x=1;x<=m;x++)cout<<s[x]<<" ";
	return 0;
}
