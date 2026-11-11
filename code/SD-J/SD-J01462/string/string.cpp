#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
char a[N];
int l[N],n,cnt;
int L;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>a[i];
	}
	for(int i=1,j=n;i<=j&&j>=i;){
		if(a[i]!=a[j]){
			int c=min(l[i],l[j]);
			cnt+=c;
			l[i]-=c;
			l[j]-=c;
			if(l[i]==0) i++;
			if(l[j]==0) j--;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
