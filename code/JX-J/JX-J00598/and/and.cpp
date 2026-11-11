#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,n1=1,m1=1,cnt=0,e[100000000];
long long a[100000000];
void f(long long a[],long long m){
	long long sum=0,p=0,q=0,o=0;
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
			if(q==m-1){
				e[p++]=sum;
				sum=0;
				o++;
				q=0;
			}
			if(sum==0){
				sum=a[i]&a[j];
				q++;
				}
			else{
				sum=sum&a[j];
				q++;
			}
			}
		}
		return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(e,0,sizeof(e));
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
			n1=n1*i;
	}
	for(long long i=1;i<=n-m;i++){
			m1=m1*i;
	}
	cnt=n1/m1;	
	f(a,m);
	sort(e,e+cnt);
	cout<<e[cnt-1];
	return 0;
}
