#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e6+10;
int n;
long long m,a[MAX],f,c,b[MAX],s[MAX],k,t,sum=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    	cin>>a[i];
    	b[i]=a[i];
	}
	if(n%2==1){
		f=n/2;
		c=a[f];
		for(long long i=0;i<f;i++){
			k=c-a[i];
			s[i]=s[i-1]+k;
			if(s[i]==m){
				t=i;
				break;
			}
		}
	}
	else{
		f=n/2+1;
		c=(a[f]+a[f+1])/2;
		for(long long i=0;i<f+1;i++){
			k=c-a[i];
			s[i]=s[i-1]+k;
			if(s[i]==m){
				t=i;
				break;
			}
		}
	}
	for(long long i=0;i<=t;i++){
		b[i]=c;
	}
	for(long long i=0;i<n;i++){
		if(b[i]==c){
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
