#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long sum=0;
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	long long jindu=0;
	int j=n;
	int i=1;
	while(jindu<=ceil(sum/2.0)){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				jindu+=a[j];
				a[i]-=a[j];
				j--;
			}else {
				ans+=a[i];
				jindu+=a[i];
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				jindu+=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				jindu+=a[i];
				i++;
			}else if(a[i]==a[j]){
				jindu+=a[i];
				j--;
				i++;
			}
		}
		if(i==j) break;
	}
	cout<<ans;
	return 0;
}
