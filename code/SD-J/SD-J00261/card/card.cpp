#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],a1[500005],a1i,a1chong[300005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		a1i=1;
		for(int j=i;j<n;j++){
			if(a1chong[a[j]]!=0){
				a1i=a1chong[a[j]];
				for(int k=a1i;k<n;k++)a1[k]=0;
			}
			a1chong[a[j]]=a1i;
			a1[a1i++]=a[j];
		}
		for(int j=1;j<=a1i;j++){
			ans[a1[j]]++;
		}for(int k=0;k<n;k++){
			a1[k]=0;
			a1chong[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
