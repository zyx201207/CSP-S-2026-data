#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,cnt,sum=1;
char c[114514];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int p=0;
		char ch;
		cin>>p>>ch;
		for(int j=sum;j<=sum+p-1;j++) c[j]=ch;
		sum+=p;
		d+=p;
	}
	for(int i=1;i<=d/2;i++)
		if(c[i]!=c[d-i+1]) cnt++;
	cout<<cnt;
	return 0;
}	