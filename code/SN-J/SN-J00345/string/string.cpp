#include<bits/stdc++.h>
using namespace std;
long long n,a,m=1,num;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s[m]=c;
			m++;
		}
	}
	m--;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1])  num++;
	}
	cout<<num;
	return 0;
} 
