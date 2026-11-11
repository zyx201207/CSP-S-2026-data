#include <bits/stdc++.h>
using namespace std;
vector<string>s(1000000);
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	long long n,a,b=-1,ant=0,l=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[l]=c;
			l++;
		}
		b+=a;
	}
	int m=0;
	while(m!=b){
		if(s[m]!=s[b])
			ant++;
		m++;
		b--;	
	}
	cout<<ant;
	return 0;
}
