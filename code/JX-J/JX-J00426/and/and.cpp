#include<bits/stdc++.h>
using namespace std;
int n,m,a[210000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=ans) ans=a[i];
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>=ans) ans=a[i]&a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
