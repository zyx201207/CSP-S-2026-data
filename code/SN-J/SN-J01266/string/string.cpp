#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[100005];
bool b[1000005];
string c;
int main(){
	freopen("string.in","r",stdin);
    freopen("stringl.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){//3 2a 2b 1c
		for(int j=n;j>=1;j--){
		if(c[i]!=c[j]&&a[i]!=a[j]){
			s+=a[i];
			a[j]=a[i];
			c[j]=c[i];
		}
		}
	}
	cout<<s;
	return 0;
}
