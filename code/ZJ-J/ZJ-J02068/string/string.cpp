#include<bits/stdc++.h>
#define inf 200005
using namespace std;
int n,a[inf];
long long sum;
char str[inf];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//  no"//"!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>str[i];
	}
	int l=1,nowl=0,r=n,nowr=0;
	while(l<r){
		int len=min(a[l]-nowl,a[r]-nowr);
		if(str[l]!=str[r])sum+=len;
		nowl+=len;
		nowr+=len;
		l+=nowl/a[l];
		r-=nowr/a[r];
		nowl%=a[l];
		nowr%=a[r];
	}
	cout<<sum;
	return 0;
}
