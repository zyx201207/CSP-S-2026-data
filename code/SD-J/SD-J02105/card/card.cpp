#include<bits/stdc++.h>
using namespace std;
long long n,a[500011],m,b[500011],c[300011];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long sd=i;
		fill(b+1,b+n+1,0);
		for(int j=i;j<=n;j++){
			int s=0;
			for(int l=i-1;l<sd;l++){
				if(a[sd]==b[l]){
					s==l;
					break;
				}
			
			}
			b[sd]=a[j];
			if(s!=0)sd=s;
			else sd++;

		}
		for(int j=i-1;j<=sd;j++){

			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
