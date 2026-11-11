#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char x[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ioi;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>x[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]){
			if(x[i]!=x[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			if(x[i]!=x[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else{
			if(x[i]!=x[j]) ans+=a[i];
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}