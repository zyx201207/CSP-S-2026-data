#include<bits/stdc++.h>
using namespace std;
long long int a[20005],sum=0,n,summ=0;
char s[20005],b[50000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=1;
	cin>>a[1];
	cin>>s[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		if(s[i]==s[i-1]){
			sum=0;
		}
		else{
			sum++;
		}
	}
	if(sum==0){
		cout<<"0";
		return 0;
	}
	if(n==2&&a[1]>a[2]){
		cout<<a[2];
	}
	else if(n==2&&a[1]<a[2]){
		cout<<a[1];
	}
	else{
		cout<<a[1];
	}
	return 0;
}