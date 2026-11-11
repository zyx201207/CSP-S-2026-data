#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	long long ans=0;
	for(int i=1;i<j;){
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if(a[i]==a[j]){
				j--;
				i++;
			}
			else{
				a[i]-=a[j];
				j--;
			}
		}
		else if(c[i]!=c[j]){
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[j];
				j--;
				i++;
			}
		}
//		cout<<i<<':'<<a[i]<<' '<<j<<':'<<a[j]<<endl;
	}

	cout<<ans;
	return 0;
} 
