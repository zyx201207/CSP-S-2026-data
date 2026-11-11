#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=-1;
	for(int i=1;i<=n;i++){
		int sum=32767;
		for(int j=0;j<m;j++){
			sum &=a[i+j] & sum;
		}
		if(sum>max){
			max=sum;
		}
	}
	cout<<max;
	return 0;
}
