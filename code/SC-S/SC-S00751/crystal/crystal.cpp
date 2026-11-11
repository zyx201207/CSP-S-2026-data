#include<bits/stdc++.h>
using namespace std;
int n,m,cc=0;
const int N=5e5+10;
int a[N];
int hh(int x,int y){
	int z=x+y;
	z/=2;
	//cout<<z<<" "<<x<<" "<<y<<endl;
	int cha=0;
	for(int i=x;i<=z-x+1;i++){
		cha+=a[z+1]-a[i];
	}
	//cout<<cha<<endl;
	if(cha<m){
		cc=cha;
		return hh(z,y);
	}
	if(cha>m){
		cc=cha;
		return hh(x,z);
	}
	if(cha==m){
		return z;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int k=hh(1,n);
	for(int i=n;i>=1;i--){
		if(a[i]==a[k]){
			k=i;
			break;
		}
	}
	cout<<k;
	return 0;
}