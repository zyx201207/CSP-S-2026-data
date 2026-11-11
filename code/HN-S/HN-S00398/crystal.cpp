#include<bits/stdc++.h>
using namespace std;
int m,n,sum;
int a[10011],b[110001];
bool cmp(int x,int y){
	return x<y;
}
bool c(int z){
	for(int i=z;i<=n;i++){
		if(a[i]*z-b[i]<=b[i-z]){
			return 0;
			}
		}
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];	
	}
	int left=0,right=n;
	while(left<right){
		int k=(left+right+1)/n;
		if(c(k)){
			left=k;
			}else{
				right=k-1;
			}
		}
	cout<<left;
	return 0;
}
