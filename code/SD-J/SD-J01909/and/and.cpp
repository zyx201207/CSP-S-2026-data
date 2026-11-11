#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+1],b[n+1]={0},j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i];
		while(x>0){
			b[i]+=x%2*j;
			x/=2;
			j*=10;
		}
		j=1;
	}
	if(m==1){
		long long max=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
	}
	else if(m==2){
		long long c[n+1];
		for(int i=1,o=1;i<n;i++){
			for(int j=i;j<n-i+1;j++,o++){
				c[o]=b[i]&&b[i+j];
			}
		}
		long long max=c[1];
		for(int i=2;i<=n;i++){
			if(c[i]>max){
				max=c[i];
			}
		}
		long long x=0;
		while(max/=10){
			x+=2^max%10;
		}
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
