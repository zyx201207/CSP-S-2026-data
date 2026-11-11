#include<bits/stdc++.h>
using namespace std;
char a[1000000];
long long l,s,m,j,p=1,t;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>l;
for(int i=1;i<=l;i++){
	cin>>j>>a[s+1];
	t=s+1;
	s+=j;
	for(int g=p;g<=s;g++){
		a[g]=a[t];
	}
	p=s;
}
m=(s+1)/2;
j=0;
for(int g=m+1;g<=s;g++){
	if(s%2==0){
		if(int(a[g])!=int(a[(2*m-g+1)])){
			j++;
		}
	}
	else{
		if(int(a[g])!=int(a[(2*m-g)])){
			j++;
		}
	}
}
cout<<j;


}