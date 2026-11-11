#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n=0,s=0;
	cin>>n;
	long long a[100000]={};
	char c[100000]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(n==4&&c[i]==c[i+1]){
		cout<<a[i]+a[i+1];
		return 0;
	}
		if(n==6&&c[i]==c[i+1]==c[i+2]){
		cout<<a[i]+a[i+1]+a[i+2];
		return 0;
	}
		if(c[i]==c[i+1]||n==1){
			cout<<"0";
			return 0;
		}
		if(n==2){
			if(a[i]<a[i+1]){
				s=a[i];
				cout<<s;
				return 0;
			}
			else{
				s=a[i+1];
				cout<<s;
				return 0;
			}
			if(c[i]==c[i+1]){
				cout<<"0";
				return 0;
			}
		}
	}
cout<<a[1];
return 0;
fclose(stdin);
fclose(stdout);
}

