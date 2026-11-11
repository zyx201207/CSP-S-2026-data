#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5*100005],c[3*100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]) flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(a[i]>m) break;
			for(int j=i;j<=n;j++){
				c[a[j]]++;
			} 
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			if(s.find(a[j]+'0')<s.size()){
				s.erase(s.find(a[j]+'0'));
				s+=(a[j]+'0');
			}else{
				s+=(a[j]+'0');
			}
		}
		for(int j=0;j<s.size();j++){
			c[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
