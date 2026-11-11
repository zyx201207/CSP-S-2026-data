#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	long long a;
	char s;
}c[N];
long long b[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].s;
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		for(long long j=sum;j<sum+c[i].a;j++){
			b[j]=c[i].s-'0';
		}
		sum+=c[i].a;
	}
	sum--;
	long long z=0,z1=0,z2=0,cnt=0;
	if(sum%2==1){
		z=sum/2+1;
		for(long long i=z-1;i>=1;i--){
			if(b[i]!=b[sum-i+1]){
				cnt++;
			}
		}
	}
	else{
		for(int i=sum;i>=sum/2;i--){
			if(b[i]!=b[sum-i+1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
