#include<bits/stdc++.h>
using namespace std;
long long a[200100],n;
char c[200100];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				j--,i++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}else{
				ans+=a[i];
				j--,i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
