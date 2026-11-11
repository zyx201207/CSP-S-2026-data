#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen<"string.in","r",stdin>;
	freopen<"string.out","w",stdout>;
	int n;
	cin>>n;
	int s[2*n];
	for (int j=1;j<=2*n;j++){
		s[j]=0;
	}
	int z=0;
	for (int i=1;i<=2*n;i++){
		cin>>s[i];
		if(i%=1) z+=s[i+1];
		else z+=s[i];
	}
	cout<<z/2;
	
	return 0;
}
