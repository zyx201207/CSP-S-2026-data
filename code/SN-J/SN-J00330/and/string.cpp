#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   string a;
getline(cin,a);
int n=100000;
for(int i=0;i<n;i++){
	if(a[i]==a[i-1]){
		break;
	}
}
cout<<0;
}
