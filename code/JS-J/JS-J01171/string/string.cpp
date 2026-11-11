#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j])    ans+=a[j];
			a[i]-=a[j],j--;
		}else if(a[i]==a[j]){
			if(c[i]!=c[j])    ans+=a[j];
			i++,j--;
		}else{
			if(c[i]!=c[j])    ans+=a[i];
			a[j]-=a[i],i++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
