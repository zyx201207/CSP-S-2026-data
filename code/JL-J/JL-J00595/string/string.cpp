#innclude<bits/stdc++.h>
#include<string>
using namespce std;
int main(){
	string a[200000];
	long long s[200000];
	long long n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
	if(a[i]==a[n]){
		cout<<"0";
		return 0;
		break;
		}
	}
	return 0;
}
