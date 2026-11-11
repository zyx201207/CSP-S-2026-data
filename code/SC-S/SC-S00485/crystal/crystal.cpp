#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int a[500010];
long long n,m,zw=1,p=1;
int num=zw;
int f1(int o){
	int np=0;
	for(int i=p;i<o;i++){
		np=np+a[o]-a[i];
		
	}
	return np;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	
	while(m>0){
		for(int i=p+1;i<=n;i++){
			if(f1(i)>m){
				break;
			}
			//cout<<f1(i)<<'\n';
			zw++;
			/*b[i]=b[i-1]+a[i]-a[i-1];//注意b下标
			c[i]=c[i-1]+b[i];
			cout<<b[i]<<'\n';*/
		}
		m=m-zw-1;
		p=p+zw-1;
		num=num+zw-1;
		zw=1;
		//cout<<zw<<'\n';
	}
	cout<<num;
	return 0;
}