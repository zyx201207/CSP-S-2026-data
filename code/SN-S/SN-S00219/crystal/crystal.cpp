#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=1,anslin=1;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=a[n],f=n;i>=a[1]&&f>=2;i--){
		if(i=a[f-1]){
			f-=1;
		}
		m2=m1;
		anslin=1;
		for(int j=f-1;j>=1;j--){
			if(i-a[j]<=m2){
				anslin++;
				m2=m2-(i-a[j]);
				
			}
			else{
				break;
			}
		}
		ans=max(ans,anslin);
		
	}
	
	cout<<ans;
	return 0;
}
