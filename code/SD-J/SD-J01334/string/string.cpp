#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	for(int i=1,j=n;i<j;){
		int m=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=m;
		}
		a[i]-=m;
		a[j]-=m;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
}
