#include<bits/stdc++.h>
using namespace std;
int a[100];
char c1[100];
int main(){
int n;cin>>n;
for(int i=0;i<=n;i++){
	cin>>a[i]>>c1[i];
	if(c1[i-1]==c1[i]){
		cout<<"0";
	}
}
return 0;
}
