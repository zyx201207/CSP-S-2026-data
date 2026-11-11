#include<bits/stdc++.h> 
using namespace std;
long long n, m, a[200005];
long long sum=0;
long long zejz(long long a){
	
	long long rst = 0, fz = 0;
	if(a==0) rst = 0;
	else if(a==1) rst = 1;
	else{
		while(a>0){
			rst = rst*10 + a%2;
			a/=2; 
		}
	}
	while(rst>0){
		fz = fz*10 +rst%10;
		rst /= 10;
	}
	rst = fz;
	return rst;
}
long long zsjz(long long a){
	long long sum=0, s=0;
	while(a>0){
		sum += a%10 * pow(2, s);
		s++;
		sum/=10;
	}
	return sum;
}
long long ejzy(long long a, long long b){//二进制与 
	long long l=0, r=0, sum=0, fz=0;
	if(a>=b){
		while(b>0){
			if(a%10==b%10) sum = sum*10 + 1;
			else sum = sum*10 + 0;
			a/=10;
			b/=10;
		}
	}else{
		while(a>0){
			if(a%10==b%10) sum = sum*10 + 1;
			else sum = sum*10 + 0;
			a/=10;
			b/=10;
		}
	}
	while(sum>0){
		fz = fz*10 +sum%10;
		sum /= 10;
	}
	sum = fz;
	return sum;
}
void mj(long long q, long long n, long long s){
	if(s>1){
		for(long long i=q;i<=n;i++){
			mj(i, n, --s);
		}
	}else{
		for(long long i=q;i<=n;i++){
			sum = max(sum,zsjz(ejzy(zejz(a[q]),zejz(a[i]))));
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!记得取消注释 
	
	//输入
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	
	mj(1,n,m);
	cout << sum;
	
 		
	return 0;
}
