#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a=0,sd=0,b=0;
	char s2,t;
	int s1;
	string p[10001]={};
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		sd=sd+s1;
		if(t==s2){
			cout<<0;
			return 0;
		}
		t=s2;
		b=a;
		for(int j=a;j<s1+b;j++){

			p[j]=s2;
			a++;
		}
		}
//cout<<sd/2;
for(int i=0;i<n;i++){
	cout<<p[i];
}
	return 0;
} 
