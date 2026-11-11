#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[200010];
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,maxn=-2e9;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>b[i];
    	maxn=max(maxn,a[i]);
	}
	if(maxn<=500){
		string s="";
		for(int i=1;i<=n;i++){
			while(a[i]){
				s.push_back(b[i]);
				a[i]--;
			}
		}
		int m=s.size();
		s=" "+s;
		int ans=0;
		for(int i=1;i<=m/2;i++){
//			cout<<i<<" "<<n-i+1<<" "<<s[i]<<" "<<s[n-i+1]<<"\n";
			if(s[i]!=s[m-i+1]){
				ans++; 
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}

