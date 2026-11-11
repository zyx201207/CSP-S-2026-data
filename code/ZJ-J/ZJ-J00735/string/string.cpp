#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
ll n,sum,l,r;
char ch[200005],sch;
ll a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r]) sum+=min(a[l],a[r]);
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else a[r]-=a[l],l++;
	}
	cout<<sum;
}
