#include<bits/stdc++.h>
using namespace std;long long a[100001];
		char s[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	long long n;
	cin>>n;
	string b;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long ans=0;int j=n;
	for(int i=1;i<=n/2&&j>=n/2;i++){
		if(s[i]==s[j]&&(a[i]+a[j])%2!=0){
				j--;i++;
				continue;
			}
			else if(s[i]==s[j]&&(a[i]+a[j])%2==0){
				ans++;
			}
			else if(a[i]==a[j]&&s[i]!=s[j]){
				ans+=a[i];
			}
			else{
				ans+=abs(a[i]-a[j]);
			}
			
			j--;
		}
		cout<<ans;
	return 0;
}
