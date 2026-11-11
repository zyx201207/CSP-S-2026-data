#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s,a[500001],b[300001],f[300001];
bool ff=1,c[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	    if(a[i]>a[i+1]){
	    	ff=0;
		    break;
	    }
	if(ff==1){
		for(int i=1;i<=n;i++){
			s=1;
			while(a[i+s]==a[i])s++;
			s--;
			cout<<i+s<<' ';
			i+=s;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)c[j]=0;
		for(int j=i;j<=n;j++){
			ff=0;
	    	for(int l=i;l<j;l++){
	    		if(a[l]==a[j]&&c[l]==0&&ff==0)ff=1;
	    		if(ff==1)c[l]=1;
			}
		}
		for(int j=i;j<=n;j++)
		    if(c[j]==0)b[a[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
}