#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long h,n,a;
	char d;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		h=h+a;
		cin>>d;
	}if(h%2==0){
		cout<<h/2;
	}else{
		cout<<h/2+1;
	}
	return 0;
}