#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]==0) i++;
		if(a[j]==0) j--;
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				a[j]=0;
			}
			else{
				a[j]-=a[i];
				ans+=a[i];
				a[i]=0;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
