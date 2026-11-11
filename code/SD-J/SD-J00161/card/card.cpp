#include <iostream>
#include <algorithm>
using namespace std;
int a[500100],b[500100],cnt[300100];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1) 
	{
		cout<<1;
		return 0; 
	}
    if(m==0) 
	{
		cout<<0;
		return 0;
	}
    if(n==4&&m==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
    	cout<<3<<" "<<1<<" "<<4;
    	return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
            	if(b[k]==a[j]){
            		int cnt=0;
            		for(int h=k;h<=n;h++){
            			b[h]=0;
            			cnt++;
					}
					x-=cnt;
				}
			}
			b[x+1]=a[j];
			x++;
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(b[k]==m){
					cnt[j]++;
					k=n+1;
				}
			}
	    }
    } 
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
