#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j;
long long ans;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	i=1;
	j=n-i+1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[j];
				i++;
				j--;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
