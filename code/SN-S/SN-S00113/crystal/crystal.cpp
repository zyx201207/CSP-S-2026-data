#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,q=0;
	int a[90000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mina=1000000;
	for(int i=n-1;i>1;i--){
		int sum=0;
		for(int j=i-1;j>=0;j--){
			sum+=a[i]-a[j];
			
		}
		if(sum<mina){
			mina=sum;
			q=i;
		}
	}
	int num=1;
//	for(int i=0;i<n-1;i++){
//		int j=i+1;
//		if(a[i]==a[j]){
//			num++;
//		}
//	}
	cout<<q+num;
}
