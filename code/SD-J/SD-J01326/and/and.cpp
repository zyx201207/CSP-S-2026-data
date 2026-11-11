#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;
int c[35],a[200005],b[200005],n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	c[0]=1;
	for(int i=1;i<=30;i++){
		c[i]=c[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	} 
	a[0]=c[30]-1;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=max(1,i-m);j--){
			int z=0;
			for(int i2=0;i2<=29&&a[j-1]>c[i2]&&b[i]>c[i2];i2++){
				if(a[j-1]%c[i2+1]/c[i2]==1&&b[i]%c[i2+1]/c[i2]==1){
					z=z+c[i2];
				}
			}
			if(z>a[j]) a[j]=z;
		} 
	} 
	cout<<a[m];
	return 0;
} 
