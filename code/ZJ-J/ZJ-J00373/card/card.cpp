#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[500010];
string s;
int cnt[300010],vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=char(a[i]+int('0'));
	}
	s=' '+s;
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++){
			char x=s[i];
			int pos=s.find(x);
			if(pos>=k){
				for(int j=pos;j<=i-1;j++){
					s[j]='0';
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[s[i]-'0']==0&&i>=k){
				cnt[s[i]-'0']++;
				vis[s[i]-'0']=1;
			}
			s[i]='0';
			if(i>=k) s[i]+=char(a[i]);
		}
	}
	for(int i=1;i<=m;i++){
		if(i==a[n]) cout<<n<<" ";
		else cout<<cnt[i]<<" ";
	}
	return 0;
}