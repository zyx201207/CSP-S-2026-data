#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans;
int a[N];
string c,s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			n--,i--;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[n-i+1]){
			if(a[i]<=a[n-i+1]){
				ans+=a[i];
				a[n-i+1]-=a[i];
			}else{
				ans+=a[n-i+1]; 
				a[i]-=a[n-i+1];
			}
		}
	}
	cout<<ans;
	return 0;
}

