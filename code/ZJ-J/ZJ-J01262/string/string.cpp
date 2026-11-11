#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],zong[200005],fzong[200005],lnow,rnow,lp,rp;
string c[200005];
string str;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			str+=c[i];
		}
	}
	string str2=str;
	reverse(str2.begin(),str2.end());
	for(int i=0;i<str.size()/2;i++){
		if(str2[i]!=str[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}