#include<bits/stdc++.h>
using namespace std;
#define int long long
char c[1000000];
string s;
int a[1000000],n,cp[1000000],cnt=0,sum=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cp[i]=a[i]+cp[i-1];
		while(a[i]>0){
			s+=c[i];
			cnt++;
			a[i]--;
		}
	}
	int mid=(cp[n]+1)/2;
	for(int i=0;i<=cnt/2-1;i++){
		if(s[i]!=s[cnt-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
