#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n = 0,m = 0,f=0,l=0,sum=0;
	string s;
	char c;
	cin>>n;
	for(int i =0;i<n;i++){
		m=0;
		cin>>m;
		cin>>c;
		for(int j =0;j<m;j++){
			s[f+j] = c;
			l++;
		}
		f+=m;
	}
	int z = l/2;
	l--;
	for(int i =0;i<z;i++){
		if(s[i]==s[l-i]){
		}
		else{
			s[l-i]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
