#include <bits/stdc++.h>
using namespace std;
#define long long


signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s;
int a,b,k=0,l=0;
char s1;

cin>>a;
for(int i=0;i<a;i++){
	b=0;
	cin>>b;
	l=b+l ;
	cin>>s1;
	for(int i=0;i<b;i++){
		s[k]=s1;
		k++;
	}
	
}

int p=0,b1;
if(l%2!=0){
	l++;
}
while(p!=l){
	if(s[p]==s[l]){
		p++;
		l--;
	}else{
		s[l-1]=s[p];
		b1++;
		p++;
		l--;
	}
	
}
cout<<b1;












return 0;



}
