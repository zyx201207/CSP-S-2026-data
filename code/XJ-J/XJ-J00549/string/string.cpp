#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==0)i++;
		if(a[j]==0)j--;
		if(s[i]!=s[j]){
			if(a[i]>=a[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}
			if(a[j]>a[i]){
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}
		}
		else{
			if(a[i]>=a[j]){
				a[i]-=a[j];
				a[j]=0;
			}
			if(a[j]>a[i]){
				a[j]-=a[i];
				a[i]=0;
			}
		}
	}cout<<ans;
	return 0;
}
