#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[1000000];
int a1[1000000];
int b=1;
int Max=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	sort(a+0,a+n,cmp);
	sort(a1+0,a1+n,cmp);
	for(int i=1;i<n;i++){
		if((a[i]-a[i-1])*b<=m){
			m-=(a[i]-a[i-1])*b;
			a[i-1]=a[i];
			b++;
		}else{
			if(Max<=b) Max=b;
			m+=a[i-b]-a1[i-b];
			b--;
		}
	}
	cout<<Max;
	return 0;
}
