#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char b;
	char s[10000]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int i=0;i<a;i++){
			s[i]=b;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
}