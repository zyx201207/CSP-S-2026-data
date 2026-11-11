#include<bits/stdc++.h>
#define ac ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int n;
int l,r;
ll ans;
ll a[2001020];
char c[2001020];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ac;
	cin>>n;
	l=0;
	r=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

