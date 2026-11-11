#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],ans;
char c[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]<a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
		else if(a[i]>a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
