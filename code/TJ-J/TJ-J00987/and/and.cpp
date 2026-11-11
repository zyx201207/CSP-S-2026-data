#include <bits/stdc++.h>
using namespace std;
int abc(int a,int b){
	int o=0,oo=0;
	while(a){
		o=o*10+a%10;
		a/=10;
	}
	while(b){
		oo=oo*10+b%10;
		b/=10;
	}
	int zxd=0;
	zxd=o&oo;
	return zxd;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,arr[210000],zuida=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n-1;j++){
			int sb=abc(arr[j],arr[j+1]);
			if(sb>zuida){
				zuida=sb;
			}
		}
	}
	cout << arr[n-1];
	return 0;
}
