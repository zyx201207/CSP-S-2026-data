#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int r(int a){
	long long wf[10001];
	long long wz[10001];
	int i=1;
	while(a!=0){
		int d=a%2;
		wf[i]=d;
		a/=2;
		i++;
	}
	for(int k=i;k>=1;k--){
		wz[i-k+1]=wf[k];
	}
	for(int k=1;k<=i;k++){
		return wz[k];
	}
}
int sh(int h){
	int i=1,s=0;
	while(h!=0){
		int d=h%10;
		s=s+pow(2,i)*d;
		h/=10;
		i++;
	}
}
int an(int o,int g){
	long long a=r(o),b=r(g);
	return sh(a&&b);
}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ma=LLONG_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){	
			if(an(i,j)>=ma){
				ma=an(i,j);
			}
		}
	}
	cout<<ma;
	return 0;
}