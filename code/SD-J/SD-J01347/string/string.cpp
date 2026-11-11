#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
unsigned long long ans;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int i=1,j=n;
	while(i<=j){
		if(s[i]==s[j]){
			if(a[i]==a[j]){
				i++,j--;continue;
			}
			if(a[i]<a[j]) a[j]-=a[i],i++;
			else a[i]-=a[j],j--;
		}
		else{
			if(a[i]<a[j]) ans+=(unsigned long long)(a[i]),a[j]-=a[i],i++;
			else if(a[i]==a[j]) ans+=(unsigned long long)(a[i]),i++,j--;
			else ans+=(unsigned long long)(a[j]),a[i]-=a[j],j--;
		}
	}
	cout<<ans;
	return 0;
}
