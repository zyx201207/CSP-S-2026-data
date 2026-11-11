#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int M=1e6+5;
const int mod=1e9+7;
ll n,ans,cnt;
ll q[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;string b;
		cin>>a>>b;
		q[i]=a;
		s=s+b;
		ans+=a;
	}int l=0,r=n-1;
	while(l<r){
		int mid=min(q[l],q[r]);
		q[l]-=mid,q[r]-=mid;
		if(s[l]!=s[r])
			cnt+=mid;
		if(q[l]==0)l++;
		if(q[r]==0)r--;
	}cout<<cnt;
	return 0;
}

