#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int t=n;
	for(int i=1;i!=t;){
		if(a[i]>=a[t])
		{
			if(c[i]!=c[t]){
				ans+=(long long)a[t];
			}
			a[i]-=a[t];
			t--;
		}
		else
		{
			if(c[i]!=c[t]){
				ans+=(long long)a[i];
			}
			a[t]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
