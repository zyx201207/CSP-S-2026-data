#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[5005],b[5005][2],c[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++){
		for(int i=j;i<=n;i++){
			b[a[i]][1]++;
			if(b[a[i]][1]>=1){
				for(int i=b[a[i]][2];i<a[i];i++){
					b[i][1]=0;
				}
			}
		b[a[i]][1]++,b[a[i]][2]=a[i];

		}
		for(int i=1;i<=m;i++)if(b[i][1]&&c[i]==0)c[i]=j;
		for(int i=1;i<=n;i++)b[i][1]=0,b[i][2]=0;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
} 
