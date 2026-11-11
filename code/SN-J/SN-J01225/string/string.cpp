#include <bits/stdc++.h>
using namespace std;
long long n;
char s[200000],z[200000];
long long m,c[200000],l=1,g=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cin>>z[i];
	}
	for(int i=1;i<=n;i++){
		for (int j=1;j<=c[i];j++){
			s[l]=z[i];
			l++;
		}
	} 
	for(int i=1;i<=l;i++){
		if(s[i]!=s[((l-1)/i)+i]) {
			g++;
		}
	}
	cout<<g;
}
