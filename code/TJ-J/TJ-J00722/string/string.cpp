#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum = 0;
	cin>>n;
	int a[n];
	char c[n];
	string str = "";
	for(int i = 0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	
	if(sum%2 == 0){
		
	}else{
		cout<<n-1;
	}

	return 0;
} 
