#include<bits/stdc++.h>
using namespace std;
bool ishw(string s){
	int sz=s.size();
	if(sz==1){
		return 1;
	}
	if(sz==2){
		if(s[0]==s[1])return 1;
		return 0;
	}
	for(int i=0;i<((sz-1)/2);++i){
		if(s[i]!=s[sz-1-i])return 0;
	}
	return 1;
}
long long n,a[200001],sum,ans,a2[200001],cnt=1;
char c[200001];
bool flag=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];++j){
			s+=c[i];
		}
	}
	if(ishw(s)==1){
		cout<<0;
		return 0;
	}
	if(sum==1){
		cout<<0;
		return 0;
	}
	if(sum==2){
		if(s[0]==s[1]){
			cout<<0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	if(sum%2==0){
		for(int i=0;i<(sum/2);++i){
			if(s[i]!=s[sum-1-i]){
				ans++; 
			}
		}	
		cout<<ans;
		return 0;	
	}
	for(int i=0;i<((sum-1)/2);++i){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
