#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,r,len,c;
	long long a[1000000100];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==1){
			len=(a[i]+1)/2;
		}else{
			len=a[i]/2;
		}
	}
	cout<<c;
}
