#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,l=1,r,c;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	r=n;
	while(l<r){
		if(a[l]>a[r]&&s[l]!=s[r]){
			c+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]&&s[l]!=s[r]){
			c+=a[r];
			l++;
			r--;
		}
		else if(a[l]<a[r]&&s[l]!=s[r]){
			c+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]<a[r]&&s[l]==s[r]){
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]&&s[l]==s[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]&&s[l]==s[r]){
			l++;
			r--;
		}
	}
	cout<<c;
	return 0;
}
