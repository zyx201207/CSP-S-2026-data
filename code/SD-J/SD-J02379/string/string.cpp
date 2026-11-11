#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned int n;
	unsigned int m;
	unsigned long long ans=0;
	char s;
	cin>>n;
	unsigned long long l=0;
	for(unsigned int x=0;x<n;x++){
		cin>>m>>s;
		for(unsigned int y=0;y<m;y++){
			a[l]=s-'a'+1;
			l++;
		}
	}
	for(unsigned int x=0;x<=l/2;x++){
		if(a[x]!=a[l-x-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

