#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in",'r',stdin); 
freopen("string.out",'w',stdout); 
int n;
int a[10005];
char b[10005];
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
}
    for(int i=1;i<=n;i++){
    	if(b[i]==b[i+1]){
    		break;
		}
		cout<<0;
    }
	return 0;
}
