#include <bits/stdc++.h>
using namespace std;
long long a[200005],ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long i=1,j=n;
	while(i<j){
		if(s[i]==s[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				j--;
				i++;
			}
		}
		else{
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				j--;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
