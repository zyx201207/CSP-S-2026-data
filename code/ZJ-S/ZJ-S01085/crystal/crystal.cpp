#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
long long n,m;
long long f0(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-x);
	}
	sort(b+1,b+1+n);
	int i=1;
	long long mm=m;
	while(mm>=0&&i<=n){
		sum++;
		mm-=b[i];
		i++;
	}
	if(mm<0){
		sum--;
	}
	return sum;
}
void f1(){
	sort(a+1,a+1+n);
	cout<<f0(a[(n+1)/2]);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=0;
    	}
	}
	if(f){
		f1();
		return 0;
	}
	sort(a+1,a+1+n);
	if(abs(a[n])<=100&&n<=5000&&abs(a[1]<=100)){
		long long maxx=-0x3f3f3f3f;
		for(int i=a[1];i<=a[n];i++){
			maxx=max(maxx,f0(i));
		}
		cout<<maxx;
	}
	else if(abs(a[n])<=100000&&n<=5000&&abs(a[1]<=100000)){
		long long maxx=-0x3f3f3f3f;
		for(int i=(a[1]+a[n])/2-1000;i<=(a[1]+a[n])/2+1000;i++){
			maxx=max(maxx,f0(i));
		}
		cout<<maxx;
	}
	else if(abs(a[n])<=100&&n<=500000&&abs(a[1]<=100)){
		long long maxx=-0x3f3f3f3f;
		for(int i=(a[1]+a[n])/2-30;i<=(a[1]+a[n])/2+30;i++){
			maxx=max(maxx,f0(i));
		}
		cout<<maxx;
	}
	return 0;
}

//Oct31==Dec25?

//5 8
//-3 -1 2 2 7

//5 5
//1 2 4 8 9
