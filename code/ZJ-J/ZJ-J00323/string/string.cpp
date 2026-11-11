#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=2e5+10;
int n,l[N];
char a[N];
signed main(){ IOS;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>a[i];
	}
	int i=1,j=n,ans=0;
	while(i<=j){
		if(a[i]==a[j]){
			if(l[i]>l[j]){
				l[i]-=l[j]; j--;
			}else{
				l[j]-=l[i]; i++;
 			}
		}else{
			if(l[i]>l[j]){
				ans+=l[j];
				l[i]-=l[j]; j--;
			}else{
				ans+=l[i];
				l[j]-=l[i]; i++;
 			}
		}
	}
	cout<<ans;
	return 0;
}