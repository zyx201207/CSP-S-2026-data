#include <bits/stdc++.h>
using namespace std;
long long n;
long long cd;
struct zz{
	long long sl;
	char zf;
}a[500006];
bool f=1,f2;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==2){
		f2=1;
	}
	char bj;
	for(int i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zf;
		cd+=a[i].sl;
		if(i==1){
			bj=a[i].zf;
		}
		if(a[i].zf!=bj){
			f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(cd==1){
		cout<<0;
	}
	if(f2){
		long long num1=a[1].sl;
		long long num2=a[2].sl;
		cout<<min(num1,num2);
		return 0;
	}
	return 0;
}
