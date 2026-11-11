#include<bits/stdc++.h>
using namespace std;
long long n,a[222222],ans;
char c[222222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		long long t=min(a[i],a[j]);
		a[i]-=t,a[j]-=t;
		if(c[i]!=c[j])ans+=t;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
}
/*AK!!AC!!*/