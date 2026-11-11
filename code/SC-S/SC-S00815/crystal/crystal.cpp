#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500100],b[500100],x=1,y,ans;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=(y+m)/i){
			b[i]=a[i];
			y=y+b[i];	
			if((y+m)/i==0){
				x=(y+m)/i;
				continue;
			}
		}else{
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=x) ans++;
	}
	cout<<ans;
	return 0;
}
