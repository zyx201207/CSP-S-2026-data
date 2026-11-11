#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0,i=1,j=n;
	for(;i<=j;){
		if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[i];
			i++;
			j--;
			continue;
		}
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else{
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
