#include<bits/stdc++.h>
using namespace std;
long long n,q=0,w=0,p=1;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	long long a[10000000];
	char 	  c[10000000];
	char s[1000000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		w=w+a[i];
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=a[i];j++){
			s[p]=c[i]*j;
			p++;
		}
	}
	for(int i=1;i<=w/2;i++){
		for(int j=w/2;j>0;j--){
			if(s[i]!=s[j]){
				q++;
			}
		}
	}
		return 0;
}