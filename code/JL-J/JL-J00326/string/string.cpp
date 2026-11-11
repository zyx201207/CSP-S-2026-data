#include <bits/stdc++.h>
using namespace std;
long long n,cnt=0,ans=0,q,z;
long long m[200005];
char c[200005];
string s="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	for(int i=1,j=n;i<=n/2&&j>=(n-n/2+1);i++,j--){
		if(m[i]==m[j]){
			if(c[i]!=c[j]){
				ans+=m[i];
			}
		}else{
			q=i,z=j;
			break;
		}
	}
	for(int i=q;i<=z;i++){
		for(int j=1;j<=m[i];i++){
			s+=c[i];
			cnt++;
		}
	}
	for(int i=1,j=cnt;i<=cnt/2&&j>=(cnt-cnt/2+1);i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
