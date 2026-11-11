# include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int pre[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,qd=0,ans=0,l=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		qd+=a[i];
		pre[qd]=1;
		l+=a[i];
	}
	for(long long i=1;i<l;i++){
		pre[i]+=pre[i-1];
//		cout<<pre[i]<<" ";
	}
	for(int i=0;i<l;i++){
		if(c[pre[i]]!=c[pre[l-i-1]]) ans++;
		if(i>=l-i-1) break;
	}
	cout<<ans;
	
	
	return 0;
}
