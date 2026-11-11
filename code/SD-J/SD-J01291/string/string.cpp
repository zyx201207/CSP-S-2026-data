#include<bits/stdc++.h>
# define N 200005
using namespace std;
long long a[N];
char s[N];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(a[i]==a[j]){
			if(s[i]!=s[j]){
				ans+=a[i];
			}
			i++;
			j--;
		}
		else if(a[i]>a[j]){
			if(s[i]!=s[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			if(s[i]!=s[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}

