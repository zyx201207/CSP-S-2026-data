#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],ans=0;
char c[N];
queue<int> q1,q2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q1.push(i);
	}
	for(int i=n;i;i--) q2.push(i);
	while(q1.front()<q2.front()){
		int x=q1.front(),y=q2.front();
		if(a[x]>=a[y]){
			q2.pop();
			a[x]-=a[y];
			if(a[x]==0) q1.pop();
			if(c[x]!=c[y]) ans+=a[y];
		}else{
			q1.pop();
			a[y]-=a[x];
			if(c[x]!=c[y]) ans+=a[x];
		}
	}
	cout<<ans;
	return 0;
}

