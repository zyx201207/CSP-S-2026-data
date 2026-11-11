#include<bits/stdc++.h>
using namespace std;
long long n,m,s,k,t=30,v,a[200001],b[200001][31],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    	for(int j=0;j<=30;j++){	
    		if(a[i]==0)break;
    		b[i][j]=a[i]%2;
    		a[i]/=2;
		}
	while(1){
	    v=t;
		k=0;
		for(int i=t-1;i>=0;i--){
			s=0;
			for(int j=1;j<=n;j++)
			    if(b[j][i]==1)s++;
			if(s>=m){
				t=i;
				ans+=pow(2,i);
				break;
			}
		}
		if(v==t)break;
		for(int i=1;i<=n;i++)
			if(b[i][t]==1){
				k++;
				for(int j=0;j<=30;j++)b[k][j]=b[i][j];
			}
		n=k;
	}
	cout<<ans;
}