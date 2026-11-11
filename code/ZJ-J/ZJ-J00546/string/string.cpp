#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;){
		if(c[i]!=c[n]){
			if(a[i]>=a[n]){
				ans+=a[n];
				a[i]-=a[n];
				n--;
			}else{
				ans+=a[i];
				a[n]-=a[i];
				i++;
			}
		}else{
			if(a[i]>=a[n]){
				a[i]-=a[n];
				n--;
			}else{
				a[n]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}

