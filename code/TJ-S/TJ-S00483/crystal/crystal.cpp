#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,k,x,y,ans=-1e05,l;
	long long a[100005],cnt[100005];
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(j=1;j<=n;j++){
		for(k=1;k<=n;k++){
			x=a[j];
			y=a[k];
			
			if(a[j]>a[k]){
				a[k]=x;
				a[j]=y;
				cnt[j]=abs(x-y);
			}
		}
		for(l=1;l<=n;l++){
			if(cnt[l]<=m&&cnt[l]>ans) ans=cnt[l];
		}
		cout<<ans;
	}
	
	return 0;
} 
