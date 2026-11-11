#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,cnt=0;
	int a[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m=1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	else if(m=2){
		sort(a+1,a+n+1);
		cout<<(a[n]&a[n-1])<<endl;
		return 0;
	}
	else if(a[n]<4){
		sort(a+1,a+n+1);
		for(int i=m;i>0;i--){
			cnt=a[n-i+1]&a[n-i];
		}
		cout<<cnt<<endl;
		return 0;
	}
	return 0;
}
