#include <bits/stdc++.h>
using namespace std;
int ans;
char b;
string s;
char a[1000000000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,l;
int o=1;
cin>>n;
for(int i=1;i<=n;i++){
	
	cin>>l>>b;
	for(int p=o;p<=l+o-1;p++){
	a[p]=b;	
		}o+=l;
	}
	for(int i=1;i<=o/2;i++){
	if(a[i]!=a[o-i])ans++;	
		}cout<<ans;
return 0;
}
