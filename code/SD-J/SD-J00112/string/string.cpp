#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n;
bool f=1;
ll a[202000];
char c[202000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	char x=c[1];
	for(int i=1;i<=n;i++){
		if(x!=c[i]){
			f=0;
		}
	}
	if(f){
		cout<<"0";
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]&&c[l]==c[r]&&l!=r){
			l++;
			r--;
		}
		else if(a[l]==a[r]){
			ans+=a[l];
			l++;
			r--;
		}
		else{
			ans+=max(a[l],a[r]);
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
