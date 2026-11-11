#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long x=0,k=0;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		x+=a;
		for(int j=1;j<=a;j++) s=s+b;
	}
	x--;

	for(int i=0,j=x;i<=j;i++,j--){
		if(s[i]!=s[j]) k++;
	}
	cout<<k;
	return 0;
}
