#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
ll ans;
char c1[MAXN],c2[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
	}
	for(int i=1;i<=n;i++){
		c2[i]=c1[n-i+1];
		b[i]=a[n-i+1];
	}
	int l=1,r=1;
	while(l<=n||r<=n){
		if(c1[l]!=c2[r]) ans+=min(a[l],b[r]);
		if(a[l]==b[r]){
			l++;
			r++;
		}
		else if(a[l]>b[r]){
			a[l]-=b[r];
			r++;
		}
		else{
			b[r]-=a[l];
			l++;
		}
	}
	cout<<ans/2;
	return 0;
}

