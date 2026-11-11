#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],mj,c,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		mj=m;
		c=0;
		for(int j=i;j>=1;j--){
			if(mj>=a[i]-a[j]){
				mj-=a[i]-a[j];
				c++;
			}else{
				break;
			}
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;
} 