#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	if(a[1]>=a[2]) cout<<a[2];
	if(a[1]<a[2]) cout<<a[1];
	return 0;
}
