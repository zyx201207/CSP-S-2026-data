#include<bits/stdc++.h>
using namespace std;
int a[10005];
char c[10005];
char sum[10005];
char r[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l,zm=0;
	long long h=0,h1=0;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	else{
		h1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			l=a[i];
			for(int j=1;j<=l;j++){
				sum[j]=a[i];
			}
		}
		for(int i=1;i<=n-1;i++){
			if(c[i]==c[i+1]){
			}
			else{
				zm++;
			}
		}
		if(zm==0){
			cout<<0;
			return 0;
		}
		else{
			if(n<=2){
				if(a[1]==a[2]){
					cout<<a[1];
					return 0;
				}
				else{
					if(a[1]>a[2]){
						cout<<a[2];
						return 0;
					}
					else{
						cout<<a[1];
						return 0;
					}
				}
			}
			else{
				for(int i=1;i<n;i++){
					if(c[i]!=c[n+1-i]){
						h++;
					}
				}
				if(h!=0){
					for(int i=1;i<n;i++){
						if(c[i]!=c[n+1-i]){
							h1++;
						}
					}
					cout<<h1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	return 0;
}