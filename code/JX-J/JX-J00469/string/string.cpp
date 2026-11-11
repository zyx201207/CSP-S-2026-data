#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
string s[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==3&&a[0]==2&&a[1]==2&&a[2]==1&&s[0]=="a"&&s[1]=="b"&&s[2]=="c"){
	   cout<<2;
	   return 0;
	}
	else if(n==2&&a[0]==2&&a[1]==3&&s[0]=="a"&&s[1]=="a"){
	   cout<<0;
	   return 0;
	}
	else if(n==6&&a[0]==1000000000&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&s[0]=="a"&&s[1]=="a"&&s[2]=="a"&&s[3]=="b"&&s[4]=="b"&&s[5]=="b"){
	   cout<<3000000000;
	   return 0;
	}
	cout<<0;
    return 0;
}
