#include<bits/stdc++.h>
using namespace std;	
long long n,a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long sum=0;
	for(int i=1;i<=n/2;i++){
		if(i+1==n-i+1){
			if(s[i]!=s[i+1]){
				sum+=min(a[i],a[i+1]);
			}
			break;
		}
		if(s[i]==s[n-i+1]&&a[i]!=a[n-i+1]){
			if(a[i]>a[n-i+1]){
				sum+=a[i]-a[n-i+1];
				a[i+1]+=a[i]-a[n-i+1];
			}
			else{
				sum+=a[n-i+1]-a[i];
				a[n-i]+=a[n-i+1]-a[i];
			}
		}
		if(s[i]!=s[n-i+1]&&a[i]==a[n-i+1]){
			sum+=a[i];
		}
		if(s[i]!=s[n-i+1]&&a[i]!=a[n-i+1]){
			if(a[i]>a[n-i+1]){
				sum+=a[i];
				a[i+1]+=a[i]-a[n-i+1];
			}
			else{
				sum+=a[n-i+1];
				a[n-i]+=a[n-i+1]-a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}
