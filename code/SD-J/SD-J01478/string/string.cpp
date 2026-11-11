#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
string s;
int n;
int a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	ll ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]=(a[l]-a[r]);
			r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]=(a[r]-a[l]);
			l++;
		}else{
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
