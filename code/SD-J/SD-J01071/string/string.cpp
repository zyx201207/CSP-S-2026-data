#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	scanf("%lld",a+i);
    	scanf(" %c",c+i);
	}
	for(int i=1,j=n;i<j;){
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
				ans+=a[i];
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
