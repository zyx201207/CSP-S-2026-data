#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[99999],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(ans==0){
			ans=a[i];
		}
		else{
			ans=ans&a[i];
		}
	}
	printf("%lld",ans);
	return 0;
} 
