#include<bits/stdc++.h>
using namespace std;
int n,a[1000011],ans,js=1,m,k,o=1e9,z[10000011];
bool cpm(int x,int y){
	return (x-a[k])<=(y-a[k]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			z[i]+=abs(a[j]-a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(z[i]<o){
			k=i;
			o=z[i];
		}
	}
	sort(a+1,a+n+1,cpm);
	while(m>=0){
		if(m-abs(a[k]-a[js])<0)break;
		ans++;
		m-=abs(a[k]-a[js]);
		js++;
	}
	cout<<ans;
	return 0;
}