#include<bits/stdc++.h>
int a[1000001]={};
char b[10000001]={}; 
using namespace std;
int main (){
//freopen ("travel.in","r",stdin);
//freopen ("travel.out", "w",stdout);
int n;
cin >> n;
for(int i=0;i<n;i++){
	cin >> a[i] >> b[i];
}
char s[1000001]={};
for(int i=0;i<n;i++){
	for(int j=0;j<a[i];j++){
		s[i]=b[i];
		cout << s[i];
	}
	}
	return 0;
}
