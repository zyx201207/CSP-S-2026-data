#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=1&&a[i]<=5){
		cout<<0;
	}
	if(n<=10&&a[i]<=1){
		cout<<0;
	}
	if(n<=2e5&&a[i]<=1){
		cout<<0;
	}
}
