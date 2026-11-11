#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[2000000];
string s[2000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x;
	string y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(y==s[i-1]){
			a[i-1]+=x;	
			n-=1;
			i-=1;
		}
		else{
			a[i]=x;
			s[i]=y;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	long long sum1=0,sum2=0;
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			sum1+=a[i];
		}
		for(int i=n/2+1;i<=n;i++){
			sum2+=a[i];
		}
		cout<<min(sum1,sum2);
	}
	else{
		for(int i=1;i<=n/2+1;i++){
			sum1+=a[i];
		}
		for(int i=n/2+2;i<=n;i++){
			sum2+=a[i];
		}
		cout<<min(sum1,sum2);
	}
	return 0;
}

