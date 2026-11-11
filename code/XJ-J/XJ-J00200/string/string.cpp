#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<=n&&j>=i;i++){
		if(a[i]>a[j]&&c[i]!=c[j]){
			ans+=a[j];
			a[i]-=a[j];
			j--;
			i--;
		}
		else if(a[i]==a[j]&&c[i]!=c[j]){
			ans+=a[i];
			j--;
		}
		else if(a[i]<a[j]&&c[i]!=c[j]){
			ans+=a[i];
			a[j]-=a[i];
		}
		else if(a[i]>a[j]&&c[i]==c[j]){
			a[i]-=a[j];
			j--;
			i--;
		}
		else if(a[i]==a[j]&&c[i]==c[j]){
			j--;
		}
		else if(a[i]<a[j]&&c[i]==c[j]){
			a[j]-=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
