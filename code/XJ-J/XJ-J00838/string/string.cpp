#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int js;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int jsq=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[j]=c[i];
			\
			jsq++;
		}
	}
	int js=jsq;
	int ss=0;
	for(int i=0;i<jsq;i++){
		if(s[i]!=s[js-1]){
			ss++;
		}
		js--;
	}
	cout<<ss/2;
	return 0;
}