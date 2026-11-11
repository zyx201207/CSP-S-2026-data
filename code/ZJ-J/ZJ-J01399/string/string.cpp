#include<bits/stdc++.h>
using namespace std;
int a[200005],n,r;
long long ans;
char s[200005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<r;){
		if(a[i]>a[r]){
			if(s[i]==s[r]){
				a[i]-=a[r];
			}
			else{
				ans+=a[r];
				a[i]-=a[r];
			}
			r--;
		}
		else if(a[i]==a[r]){
			if(s[i]!=s[r]) ans+=a[i];
			i++;
			r--;
		}
		else{
			if(s[r]==s[i]){
				a[r]-=a[i];
			}
			else{
				ans+=a[i];
				a[r]-=a[i];
			}
			i++;
		}
	}
	cout<<ans;
	return 0;
}
