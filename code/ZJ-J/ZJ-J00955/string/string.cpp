#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j])ans+=min(a[i],a[j]);
		long long x;
		if(a[i]<a[j]){
			x=a[i];
			a[j]-=x;
			i++;
		}else if(a[i]==a[j]){
			i++;
			j--;
		}else{
			x=a[j];
			a[i]-=x;
			j--;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}