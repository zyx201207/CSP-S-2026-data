#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010];
ll s[500010];
ll from[500010];
ll b[500010];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
		if(i!=n&&a[i]<a[i+1]) f=1;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			if(from[a[i]]){
				for(int j=from[a[i]];j<i;j++) b[a[j]]--;
			}
			b[a[i]]++;
			from[a[i]]=i;
			for(int i=1;i<=m;i++){
				if(b[i]) s[i]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	}
	else{
		for(int i=1;i<=n;i++) s[a[i]]=max(s[a[i]],n-i+1);
		for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	}	
	return 0;
} 
