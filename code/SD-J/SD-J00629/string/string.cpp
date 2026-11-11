#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=n;i>=1;i--){
		b[i]=b[i+1]+a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+a[i];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],b[j])-max(a[i-1],b[j+1]);
		}
		if(a[i]==b[j])i++,j--;
		else if(a[i]<b[j])i++;
		else if(a[i]>b[j])j--;
	}
	cout<<ans;
	return 0;
}
