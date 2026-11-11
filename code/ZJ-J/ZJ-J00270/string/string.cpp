#include<bits/stdc++.h>
using namespace std;
int n,l;
long long a[200005];
int ans[10001];
char c[200005];
void f(long long x){
	int k=0;
	for(int i=1;i<=15;i++){
		ans[i]+=(x%10+k);
		x/=10;
		k=ans[i]/10;
		ans[i]=ans[i]%10;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j])f(a[j]);
			a[i]-=a[j];
			j--;
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j])f(a[i]);
			i++;
			j--;
		}
		else{
			if(c[i]!=c[j])f(a[i]);
			a[j]-=a[i];
			i++;
		}
	}
	for(int i=1;i<=15;i++){
		if(ans[i]!=0)l=i;
	}
	for(int i=l;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
