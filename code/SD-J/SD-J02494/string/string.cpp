#include <bits/stdc++.h>
using namespace std;
char a[200005],b[10000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long t,t1=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>t>>a[i];
		for(int j=t1;j<t1+t;j++){
			b[j]=a[i];
		}
		t1+=t;
	}
	for(int i=0;i<t1/2;i++){
		if(b[i]!=b[n-i-1]){
			ans++;
		}
	}
	ans+=n;
	cout<<ans;
	return 0;
}
