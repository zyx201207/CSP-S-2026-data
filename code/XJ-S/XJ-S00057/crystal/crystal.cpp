#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=1000000005;
int a[N],k[N][N];
int num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//
	//for(int i=1;i<=n;i++){
	//	cout<<a[i];
	//}
	//cout<<endl;
	//
	k[1][1]=1;
	int minll=M;
	for(int i=1;i<=n-1;i++){
		k[1][i]=0;
		k[2][i]=a[i+1]-a[i];
		minll=min(minll,k[2][i]);
	}
	num=1;
	if(minll>m){
		cout<<num;
	}
	if(minll==m){
		num=2;
		cout<<num;
	}
	//
	//cout<<minll;
	//
	for(int i=3;i<=n;i++){
		int minl=M;
		for(int j=1;j<=n;j++){
			k[i][j]=k[i-1][j]+(i-2)*k[2][i-1];
			minl=min(minl,k[i][j]);
		}
		//
		//cout<<minl<<" ";
        //
		if(minl>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
