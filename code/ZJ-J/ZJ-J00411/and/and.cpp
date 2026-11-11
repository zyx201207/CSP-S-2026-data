#include<bits/stdc++.h>
using namespace std;
long long n,m,l,ans;
long long a[200010];
string s[200010];
int f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i];
		if(x==0) s[i]="0";
		while(x!=0){
			int r=x%2;
			if(r==1) s[i]="1"+s[i];
			else s[i]="0"+s[i];
			x/=2;
		}if(s[i].size()>l) l=s[i].size();
	}for(int i=1;i<=n;i++){
		int l1=s[i].size();
		for(int j=1;j<=l-l1;j++){
			s[i]="0"+s[i];
		}
	}for(int i=0;i<l;i++){
		int p1=0;
		for(int j=1;j<=n;j++){
			if(f[j]==0 && s[j][i]=='1') p1++;
		}if(p1>=m){
			for(int j=1;j<=n;j++){
				if(f[j]==0 && s[j][i]=='0') f[j]=1;
			}ans+=pow(2,l-i-1);
		}
	}cout<<ans;
	return 0;
}
