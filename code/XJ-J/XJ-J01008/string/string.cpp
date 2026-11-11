#include <bits/stdc++.h>
using namespace std;
long long a,b,n,c,c1,l;
char d;
char num[1599999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++ ){
		cin>>b>>d;
		for(int j=1;j<=b;j++){
			num[j+n]=d;
			
		}
		n=n+b;
		c=c+b;
	}
	l=0;
	if(c%2==1){
		c1=c/2+1;
		for(int i=1;i<c1;i++){
			if(num[i] != num[c-i+1]){
				l++;
				
			}
		}
	}else if(c%2==0){
	
		c1=c/2;
		for(int i=1;i<c1;i++){
			if(num[i] != num[c-i+1]){
				l++;
			}
		}}
	cout<<l;
	return  0;
}
