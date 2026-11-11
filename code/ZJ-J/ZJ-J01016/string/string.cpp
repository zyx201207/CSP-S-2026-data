#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long i=1,j=n;
	while(i<j){
		if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j])
				ans+=a[j];
			j--;
		}else{
			a[j]-=a[i];
			if(c[i]!=c[j])
				ans+=a[i];
			i++;
			if(a[j]==0)
				j--;
		}
	}
	cout<<ans;
	return 0;
}
