#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],ans=0;
char c[500005];
signed main(){
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<=j){
		if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j])ans+=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			a[j]-=a[i];
			if(c[i]!=c[j])ans+=a[i];
			i++;
		}
		else{
			if(c[i]!=c[j])ans+=a[i];
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
