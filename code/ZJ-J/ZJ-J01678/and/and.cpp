#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=n-2,sum=a[n-1],x=m-1;
	cout<<a[n-1]<<" ";
	while(x){
		sum&=a[i];
		cout<<a[i]<<" ";
		i--;
		x--;
	}
	cout<<endl;
	cout<<sum;
	return 0;
} 
