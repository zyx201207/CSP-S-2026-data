#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long sum;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j]) sum+=a[j];
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			if(c[i]!=c[j]) sum+=a[i];
			a[j]-=a[i];
			i++;
		}
		else{
			if(c[i]!=c[j]) sum+=a[i];
			a[i]=a[j]=0;
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
}
