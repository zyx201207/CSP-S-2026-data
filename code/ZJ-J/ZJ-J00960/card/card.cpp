#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000],cnt=1,b[10],c[10];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt==1){
				c[1]=a[j];
				cnt++;
			}
			else if(cnt==2){
				if(c[1]==a[j]){
					cnt=2;
					c[2]=0;
				}
				else{
					c[2]=a[j];
					cnt++;
				}
			}
			else{
				if(c[1]==a[j]){
					cnt=2;
					c[2]=0;
					c[3]=0;
				}
				else{
					cnt=3;
					c[3]=0;
				}
			}
		}
		if(c[1]==1){
			b[1]++;
		}
		if(c[1]==2){
			b[2]++;
		}
		if(c[2]==1){
			b[1]++;
		}
		if(c[2]==2){
			b[2]++;
		}
		c[1]=0;
		c[2]=0;
		cnt=1;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
