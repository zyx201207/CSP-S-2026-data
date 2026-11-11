#include<bits/stdc++.h>
using namespace std;
long long a[10];
string p[10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>p[i];
		if(n==1){
			if(a[i]%2==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}

	else{
		if(a[1]!=a[2] &&p[1]==p[2]){
			cout<<0;
		}
		else{
			if(a[1]==a[2] && p[1]!=p[2]){
				if(n%2==0){
					cout<<n/2*a[1];
				
				}
				else{
					cout<<a[1];
				}
			}
		}
	}
	}	
	return 0;
}
