#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[200010],f[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string> s(n+5);
	int len=0;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]!=0){
			if(a[i]&1){
				s[i]=s[i]+"1";
			}else{
				s[i]=s[i]+"0";
			}
			a[i]>>=1;
		}
		len=max(len,(int)s[i].size()); 
	}
	for(int i=1;i<=n;i++){
		int si=len-s[i].size();
		if(si!=0){
			for(int j=1;j<=si;j++){
				s[i]=s[i]+"0";
			}
		}
	}
	int ans=0;
	for(int i=len-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]==1){
				continue;
			}
			if(s[j][i]=='1'){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=1<<i;
			for(int j=1;j<=n;j++){
				if(s[j][i]=='0'){
					f[j]=1;
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}
