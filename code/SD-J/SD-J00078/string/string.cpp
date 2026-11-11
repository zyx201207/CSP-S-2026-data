#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5; 
int n;
ll a[N],len,s[N],ans,tong[N][26];
char c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
		s[i]=s[i-1]+a[i];
		for(int j=0;j<26;j++){
			tong[i][j]=tong[i-1][j];
		}
		tong[i][c[i]-'a']+=a[i];
	}
	len=s[n];
	for(int i=1;i<=n&&s[i]-a[i]+1<=(len>>1);i++){
		ll st=s[i]-a[i]+1,en=min(s[i],len>>1);
		ll kst=(len-en+1),ken=(len-st+1);
		int idst=lower_bound(s+1,s+n+1,kst)-s,iden=lower_bound(s+1,s+n+1,ken)-s;
//		cout<<idst<<' '<<iden<<' '<<a[i]<<'\n';
		if(idst==iden){
			if(c[idst]!=c[i]) ans+=ken-kst+1;
		}else{
			if(idst==iden-1){
				if(c[idst]!=c[i]) ans+=s[idst]-kst+1;
				if(c[iden]!=c[i]) ans+=ken-(s[iden]-a[iden]+1)+1;
			}else{
				if(c[idst]!=c[i]) ans+=s[idst]-kst+1;
				if(c[iden]!=c[i]) ans+=ken-(s[iden]-a[iden]+1)+1;
				ans+=(s[iden-1]-s[idst])-(tong[iden-1][c[i]-'a']-tong[idst][c[i]-'a']);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

