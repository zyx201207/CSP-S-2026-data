#include <bits/stdc++.h>
using namespace std;
const int A=2e5+10;
string a,b;
int sa[A],sb[A];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	a=' '+a;
	b=' '+b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char t;
		scanf("%d",&sa[i]);
		sb[n-i+1]=sa[i];
		cin>>t;
		for(int j=1;j<=sa[i];j++){
			a+=t;
		}
	}
	for(int i=a.size();i>=1;i--){
		b+=a[i];
	}
	long long zh=0;
	for(int i=1;i<=a.size();i++){
		if(a[i]!=a[n-i+1]){
			zh++;
		}
	}
	cout<<zh/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

