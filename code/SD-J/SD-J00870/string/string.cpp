#include<bits/stdc++.h>//powered_by_flyin2899
#define int long long//need to fix:TLE
using namespace std;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	int ans=0;
	int len=s.size();
	s=' '+s;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i])ans++;
	}
	cout<<ans;
	return 0;
}
/*#include<bits/stdc++.h>
#define int long long//need to fix:TLE
using namespace std;

int lst,now,l[200005],n;
char c[200005];

signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	l[1]=1;
	for(int i=1;i<=n;i++){
		cin>>now>>c[i];
		l[i]=lst+l[i-1];
		lst=now;
	}
	l[n+1]=lst+l[n];
	int ans=0;
	for(int i=1;i<=n;i++){
		int rr=n+1-l[i],rl=n+1-l[i+1]+1;
		now=rr;
		bool f=1;
		while(f){
			int pos=lower_bound(l+1,l+1+n,now)-l-1;
			if(l[pos]<=rl){
				f=0;
				if(c[pos]!=c[i]){
					ans+=now-rl+1;
				}
			}
			else if(c[pos]!=c[i]){
				ans+=now-l[pos]+1;
			}
			now=l[pos]-1;
		}
	}
	cout<<ans/2;
	return 0;
}*/
