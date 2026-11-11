#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0,sum=0,m=0,p=0,e=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[1]){
			num+=0;
		}else{
			num++;
		}
	}
	if(n%2==0){
		m=n/2;
	}else{
		m=n/2;
	}
	for(int i=1;i<=m;i++){
		sum+=a[i];
	}
	if(num==0){
		cout<<0;
	}else{
		cout<<sum;
	}
	return 0;
}
