#include<iostream>
#include<cmath>
using namespace std;
int n,a[200005],b[200005],t;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	b[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[s.size()-1-i]!=s[i]){
			t++;
		}
	}
	cout<<t/2;
} 
