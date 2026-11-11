#include<bits/stdc++.h>
using namespace std;
string k[200005],s[200005];
int a[200005],js[200005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1,cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		while(a[i]!=0) {
			cnt++;
			k[i]+=a[i]%2+'0';
			a[i]/=2;
		}
		if(cnt>maxn)maxn=cnt;
		cnt=0;
	}
	for(int i=1; i<=n; i++) {
		while(k[i].size()<maxn){
			k[i]+='0';
		}
			
	}
	for(int i=1; i<=n; i++) {
		for(int j=k[i].size()-1; j>=0; j--) {
			s[i]+=k[i][j];
		}
	}
	int sy=n,ans=0;
	long long sum=0;
	for(int j=0; j<s[1].size(); j++) {
		for(int i=1; i<=n; i++) {
			if(s[i][j]=='0')ans++;
		}
		if(sy-ans>=m) {
			for(int i=1; i<=n; i++) {
				if(s[i][j]=='0') {
					s[i]="ccf";
				}
				sy-=ans;
			}
		}
		ans=0;
		if(sy==m)break;
	}
	int c=0;
	for(int i=1; i<=n; i++) {
		if(s[i]!="ccf") {
			c++;
			int p=1;
			for(int j=s[i].size()-1; j>=0; j--) {
				js[c]+=int((s[i][j]-'0'))*p;
				p*=2;
			}
		}
	}
	sum=js[1];
		for(int i=2; i<=c; i++) {
			sum=sum&js[i];
		}
	cout<<sum;
	return 0;
}
