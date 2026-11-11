#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long sum=0;
	for(int i=1,j=n;i<=j;){
		if(b[i]!=b[j]){
			//cout<<b[i]<<" "<<b[j]<<" ";
			sum+=min(a[i],a[j]);
		}
		if(a[j]>a[i]){
			a[j]-=a[i];
			i++;
			continue;
		}
		if(a[j]<a[i]){
			a[i]-=a[j];
			j--;
			continue;
		}
		if(a[i]==a[j]){
			i++,j--;
			continue;
		}
	}
	cout<<sum;
	return 0;
}
