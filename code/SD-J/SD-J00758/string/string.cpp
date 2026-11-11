#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
unsigned long long ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j])
			ans+=(unsigned long long)min(a[i],a[j]);
		if(a[i]==a[j])
			i++,j--;
		else if(a[i]<a[j])
			a[j]-=a[i],i++;
		else
			a[i]-=a[j],j--;
	}
	cout<<ans;//RP++
	return 0;
}//qwq 
