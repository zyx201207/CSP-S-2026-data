#include<bits/stdc++.h>
using namespace std;
long long n,m,c[200008],suma=1,sumb=1;
//int zh(int n){
//	int s=0;
//	while(n!=0){
//		s=s*10+n%2;
//		n=n/2;
//	}
//	return s;
//}
//long long ch(long long n){
//	long long s=1;
//	long long ans=0;
//	while(n!=0){
//		ans+=n%10*s;
//		n=n/10;
//		s=s*2;
//	}
//	return ans;
//}
//int andd(long long a,long long b){
//	int sum=0;
//	if(a==b){
//		return a;
//	}
//	a=zh(a);
//	b=zh(b);
//	while(a!=0&&b!=0){
//		cout<<a<<" "<<b<<" "<<sum<<endl;
//		sum=sum*10+(a%10)&&(b%10);
//		a=a/10;
//		b=b/10;
//	}
//	return ch(sum);
//}
void js(long long a,long long b){
	if(c[suma]&&c[sumb]<=c[a]&&c[b]){
		suma=a;
		sumb=b;
	}
	if(a==n-1){
		return;
	}
	if(b<n){
		b++;
	}else{
		a++;
		b=a+1;
	}
	js(a,b);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ma=-1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ma=max(ma,c[i]);
	}
	if(m==1){
		cout<<ma;
	}else{
		js(1,2);
		cout<<c[suma]&&c[sumb];
	}
	return 0;
}