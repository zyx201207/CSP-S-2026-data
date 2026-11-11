#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;i++,j--){
		if(c[i]!=c[j]){
			sum+=min(a[i],a[j]);
		}
		if(a[i]<a[j]){
			a[j]-=a[i];
			j++;
		}
		else if(a[i]==a[j]){
			continue;
		}
		else{
			a[i]-=a[j];
			i--;
		}
	}
	cout<<sum;
	return 0;
}
