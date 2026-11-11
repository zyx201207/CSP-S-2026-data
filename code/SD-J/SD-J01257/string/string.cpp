#include<bits/stdc++.h>
using namespace std;
struct A{
	long long a;
	char b;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
long long n,x;
cin>>n;
if(n==1){
	cout<<0;
	return 0;
} 
A a[n+1];
long long n2=1,sum2=0;
string s;
s+=" ";
for(long long i=1;i<=n;i++){
	cin>>a[i].a>>a[i].b;
	//s[n2]=a[i].b;
	//s[a[i].a+n2]=a[i].b;
	//for(long long j=n2;j<=a[i].a+n2-1;j++){
	//	s+=a[i].b;
//	}
	//n2=s.size()+1;
	sum2+=a[i].a;
	} 
long long sum=0,jsql=1,jsqr=n;

for(long long i=1;;i++){
//cout<<a[jsql].b<<" "<<a[jsqr].b<<endl;
	if(jsql>=jsqr) break;
	if(a[jsql].b!=a[jsqr].b) sum+=min(a[jsql].a,a[jsqr].a);
	if(a[jsql].a<a[jsqr].a){
		i+=a[jsql].a-1;
		jsql++;
		a[jsqr].a-=a[jsql-1].a;
	}else{
		i+=a[jsqr].a-1;
		jsqr--;
		a[jsql].a-=a[jsqr+1].a;
	}
	
	//cout<<s[i]<<" "<<s[sum2-i+1]<<endl;
}
//long long l=1,r=n;
//while(l<n){
//	if(a[l].a<a[r].a&&a[l].b!=a[r].b){
		
//	}
//}
cout<<sum;
	return 0;
 } 
