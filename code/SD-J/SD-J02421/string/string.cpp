#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[20009],sum=0;
	char c[20009];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n,i=1;
	while(i!=j){
		if(c[i]!=c[j]){
			int max1=min(a[i],a[j]);
			
			sum+=max1;
		}
		if(a[i]>a[j]){
			i++;
		}
		if(a[i]<a[j]){
			j--;
		}
	}
	cout<<sum;
} 
