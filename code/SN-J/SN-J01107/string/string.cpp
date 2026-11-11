#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,mid,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	mid=sum/2+1;	
	for(int i=1;i<=n/2;i++){
		int ss=abs(a[i]-a[i-mid]);
		if(a[i]!=a[i+mid]&&c[i]==c[i+mid]){
			ans=ans+ss;
			a[i-1+mid]-=ss;
			a[i+mid]+=ss;
			}else if(c[i]!=c[i+mid]&&a[i]==a[i+mid]){
			ans+=a[i];
		}else if(c[i]!=c[i+mid]&&a[i]!=a[i+mid]){
			ans+=a[i];
			a[i+mid-1]-=ss;
		}
	}
	cout<<ans;
}
