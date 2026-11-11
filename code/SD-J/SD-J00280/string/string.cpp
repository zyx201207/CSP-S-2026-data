#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int a[N];
char b[N];
void solve(){
	int ans=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
    cin>>a[i]>>b[i];	
	}
	int l=0,r=n-1;
	while (l<r){
	if (a[l]>a[r]){
	if (b[l]!=b[r])	ans+=a[r];
	a[l]-=a[r];
	r--;
	}	
	else 
	if (a[l]<a[r]){
	if (b[l]!=b[r])ans+=a[l];
	a[r]-=a[l];
	l++;	
	}
	else {
	if (b[l]!=b[r])ans+=a[l];
	l++;
	r--;	
	}	
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while (T--)solve();
	return 0;
}

