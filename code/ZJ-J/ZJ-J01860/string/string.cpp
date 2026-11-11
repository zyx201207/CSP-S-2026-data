#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n;
ll a[N],ans;
char ch[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r]){
			ans+=max(a[l],a[r]);
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
