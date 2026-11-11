#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in""r"stdin);
	//freopen("string.out""w"stdout);
    int n,a[10005];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(a[i]==a[j]){
				cout<<"0";
		}
		break;
	}
	}
	return 0;
}
 
