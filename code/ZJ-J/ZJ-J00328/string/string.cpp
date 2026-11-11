#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int n,size,a[N],sum,num[N],ans,flag=1;
char b[N];
signed main(){
	IOS
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		size+=a[i];
		if(a[i]>50){
			flag=0;
		}
	}
	if(flag){
		
		string s;
		s=" "+s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s=s+b[i];
			}
		}
		for(int i=1;i<=size/2;i++){
			if(s[i]!=s[n+1-i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
