//郭溥森 西安辅轮中学 SN-J00639
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n;
ll a[MAXN];
string c[MAXN];
int ans,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s[MAXN];
	int L=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			s[i]=c[i];
		}
	}
	for(int i=1;i<=L;i++){
		if(s[i]==s[i+1]){
			cnt++;
		}
		if(cnt==L-1){
			cout<<0;
			return 0;
		}
	}
	for(int i=1; i<=L/2+1; i++) {
		if(s[L+1-i]!=s[i]) {
			s[L+1-i]=s[i];
			ans+=1;
		}
		else{
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
