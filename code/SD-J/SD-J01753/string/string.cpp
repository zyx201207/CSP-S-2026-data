#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005],c1[200005],b[200005];
int cnt=0,lon=0,cnt2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
	}
	int yui=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[yui]=c1[i];
			yui++;
		}
	} 
	int ads=(yui%2==1);
	lon=yui/2;
	for(int i=0;i<lon;i++){
		b[i]=c[i];
	}
	int yiu=0;
	for(int i=yui-1;i>=(lon+ads);i--){
		if(b[yiu]!=c[i]){
			cnt++;
		}
		yiu++;
	}
	cout<<cnt;
	
	return 0;
}
