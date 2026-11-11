#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum;
char c[200005];
char s1[100000005];
char s2[100000005];
long long l;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin>>n;
int k1=0,k2=0;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	l+=a[i];
}
int f=0,p=0;
for(int i=1;i<=n;i++){
	for(int j=1;j<=a[i];j++){
		k1++;
		s1[k1]=c[i];
		
		if(k1==l/2)f=1;
	}
	p=i;
	if(f==1)break;
}
f=0;
for(int i=n;i>=p;i--){
	for(int j=1;j<=a[i];j++){
		k2++;
		s2[k2]=c[i];
		
		if(k2==l/2)f=1;
	}
	if(f==1)break;
}
/*for(int i=1;i<=l/2;i++){cout<<s1[i];}
cout<<endl;
for(int i=1;i<=l/2;i++){cout<<s2[i];}*/
for(int i=1;i<=l/2;i++){
	if(s1[i]!=s2[i])sum++;
}

cout<<sum;
return 0;
//🤔🤓😋😡
}
