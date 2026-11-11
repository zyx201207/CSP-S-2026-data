#include<bits/stdc++.h>
using namespace std;
int n,mi;
long long ans;
int a[200005];
char c[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		mi=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=mi;
		}
		a[i]-=mi;
		a[j]-=mi;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
