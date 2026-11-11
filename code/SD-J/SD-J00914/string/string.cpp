#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[200001],b[200001];
char ac[200001],bc[200001];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ac[i];
	for(int i=n;i>=1;i--){b[n-i+1]=a[i];bc[n-i+1]=ac[i];}
	for(int i=1,j=1;i<=n&&j<=n;i+=0){
		if(a[i]<b[j]){
			if(ac[i]==bc[j]){
				b[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				b[j]-=a[i];
				i++;
			}
		}else if(a[i]>b[j]){
			if(ac[i]==bc[j]){
				a[i]-=b[j];
				j++;
			}else{
				ans+=b[j];
				a[i]-=b[j];
				j++;
			}
		}else{
			if(ac[i]!=bc[j])ans+=a[i];
			i++;j++;
		}
	}cout<<ans/2;
}
