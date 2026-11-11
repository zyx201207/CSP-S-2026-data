#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k=m;
		for(int j=i;j>=1;j--){
			if(k>=0&&k>=(a[i]-a[j])){
				k=k-(a[i]-a[j]);
				b[i]++;
			}else{
			    break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]>ans) ans=b[i];
	}
	cout<<ans;
	return 0;
}
