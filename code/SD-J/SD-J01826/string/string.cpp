#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans,x,sum;
char c;
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=sum;i<sum+a;i++){
			s[i]=c;
		}
		sum+=a;
	}
	x=sum-1;
	for(int i=0;i<sum;i++){
		if(s[i]!=s[x-i]){
			s[i]=s[x-i];
			ans++;
		}
		else{
			continue;
		}
	}
	cout<<ans;
	return 0;
}
