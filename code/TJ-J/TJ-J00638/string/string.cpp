#include<bits/stdc++.h>
using namespace std;
long long n=0;
struct bs{
	long long k;
	char c;
}b[200005];
long long num[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i].k;
		num[i]=num[i-1]+b[i].k;
		n+=b[i].k;
		cin>>b[i].c;
	}
	char c1,c2;
	long long t1,t2;
	if(n%2==0){
		t1=n/2;
		t2=t1+1;
	}
	else{
		t1=(n+1)/2;
		t2=t1;
	}
	for(;t1>=1;t1--,t2++){
		for(int i=0;i<m;i++){
			if(num[i]<t1&&num[i+1]>=t1){
				c1=b[i+1].c;
			}
		}
		for(int i=m-1;i>0;i--){
			if(num[i]<t2&&num[i+1]>=t2){
				c2=b[i+1].c;
			}
		}
		if(c1!=c2) ans++;
	}
	cout<<ans;
	return 0;
}











