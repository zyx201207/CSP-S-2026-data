#include <bits/stdc++.h>

using namespace std;
int n,m,d,Ma;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=d){
			d=a[i];
		}
	}
	if(n<=20){
		/*if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int b=a[i] ^ a[j];
					Ma=max(Ma,b);	
				}
			}
			cout<<Ma;
			return 0;
		}
		else if(m==n){
			int c=0;
			for(int i=2;i<=n;i++){
				a[i]=(a[i] ^ a[i-1]);
			}
			cout<<a[n];
			return 0;
		}*/
		if(m==1){
			cout<<d;
			return 0;
		}
		else{
			int y=a[n] ^ a[n-1];
			cout<<y;
			return 0;
		}
		
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int b=(a[i] ^ a[j]);
				Ma=max(Ma,b);	
			}
		}
		cout<<Ma;
		return 0;
	}
	else if(m==n){
		int c=0;
		for(int i=2;i<=n;i++){
			a[i]=(a[i] ^ a[i-1]);
		}
		cout<<a[n];
		return 0;
	}
	else if(m==1){
		cout<<d;
		return 0;
	}
	else{
		int y=a[n] ^ a[n-1];
		cout<<y;
		return 0;
	}
	return 0;
}

