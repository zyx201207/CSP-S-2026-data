#include<bits/stdc++.h> 
using namespace std;
long long n,ans=0,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=0,j=n-1;i<j;){
		if(a[i]>a[j]){
			if(b[i]!=b[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}else if(a[i]==a[j]){
			if(b[i]!=b[j]) ans+=a[j];
			i++;
			j--;
		}else{
			if(b[i]!=b[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
