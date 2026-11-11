#include <bits/stdc++.h>
using namespace std;
long long n,a,cd,t;
int d=1,fzd=1;
char b;
string c[100000005],fz[100000005];
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		cd+=a;
		for(int i=1;i<=a;i++){
			c[d++]=b;
		}
	}
	return 0;
}
