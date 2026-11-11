#include<bits/stdc++.h> 
using namespace std;
int a[200003];
char b[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	long long k=0;
	for(int i=1;i<=n;i++) k+=a[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		for(int i=1;i<=n;i++){
			if(b[i]==b[i+1]) {
				cout<<0;
				return 0;
			}
			else if(b[i]!=b[i+1]&&a[i]<a[i+1]){
				cout<<a[i];
				return 0;
			}
			else{
				cout<<a[i+1];
				return 0;
			}
		}
	}
	cout<<k/2;
	return 0;	
}
