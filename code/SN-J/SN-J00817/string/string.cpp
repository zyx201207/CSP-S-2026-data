//刘曌珩  SN-J00817  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]&&c[i]==c[j]){
			a[i]-=a[j],j--; 
		}
		else if(a[i]==a[j]&&c[i]==c[j]){
			i++,j--;
		}
		else if(a[i]<a[j]&&c[i]==c[j]){
			a[j]-=a[i],i++;
		}
		else if(a[i]>a[j]&&c[i]!=c[j]){
			a[i]-=a[j],ans+=a[j],j--;
		}
		else if(a[i]==a[j]&&c[i]!=c[j]){
			ans+=a[i],i++,j--;
		}
		else if(a[i]<a[j]&&c[i]!=c[j]){
			a[j]-=a[i],ans+=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}
