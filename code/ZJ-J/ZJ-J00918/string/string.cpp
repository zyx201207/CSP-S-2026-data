#include<bits/stdc++.h>
using namespace std;
string S;
long long n,cnt=0;
long long a[200005],ans[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		ans[i+1]=ans[i]+a[i];
	}
	long long x=ans[n-1]/2;
	if(ans[n]%2!=0) x+=1; 
	for(int i=n-1;i>0;i--){
		if(ans[i]<=x){
			a[i+1]=ans[i+1]-x;
			a[i]=a[i]-a[i+1];
			b[i+1]=b[i];
			break;
		}
		a[i+1]=a[i];
		b[i+1]=b[i];
	}
	for(long long i=0,j=n;i<=j;){
		if(b[i]!=b[j]){
			cnt+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]=a[i]-a[j];
			j--;
		}else if(a[i]<a[j]){
			a[j]=a[j]-a[i];
			i++;
		}else if(a[i]==a[j]){
			i++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
}
