#include<bits/stdc++.h>
using namespace std;
long long a,b,c=1,d,s;
char q,e,r,k[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		cin.tie(0);
cin>>a;
for(int i=1;i<=a;i++){
	cin>>b;
	cin>>q;
	for(int j=c;j<=c+b-1;j++){
		k[j]=q;
	}
	c+=b;
}
c-=1;
d=c/2;
for(int i=1;i<=d;i++){
	if(k[i]!=k[c-i+1]){
		s++;
	}
} 
cout<<s;
	return 0;
} 
