#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
	return a>b;
}
int n,m;
ll ans;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(a[0]<4){
		for(int i=0;i<n;i++){
			if(a[i]==3) ans=3;
			if(a[i]==2) ans==1;
			if(a[i]==1){
				cout<<0;
				return 0;
			}
			cout<<ans;
		}
		
	}
	else {
		cout<<a[m-1];
	}
	return 0;
}
