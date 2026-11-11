#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ans,n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				i++;
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
