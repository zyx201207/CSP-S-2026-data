#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50;
int n,a[N],ans=0,cnt=0;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i<j;){
		cnt=min(a[i],a[j]);
		ans+=cnt;
		if(b[i]==b[j]) ans-=cnt;
		a[i]-=cnt,a[j]-=cnt;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
