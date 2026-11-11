#include<bits/stdc++.h>
using namespace std;
char s[10001];
char c[10001];
int a[10001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<a[0];i++){
		s[i]=c[0];
	}
	for(int i=a[0];i<a[0]+a[1];i++){
		s[i]=c[1];
	}
	for(int i=a[1];i<a[1]+a[2];i++){
		s[i]=c[2];
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[n-i]){
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}
