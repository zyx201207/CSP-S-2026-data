#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> vis,mp;
int a[300010];
int s[300010];
int top=0;
signed main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin >>m>>n;
	int head=1;
	for(int i=1;i<=m;i++) cin >>a[i];
	for(int i=m;i>=1;i--){
		s[++top]=a[i];
		if(vis[a[i]]){
			for(int j=head;j<top;j++){
				if(s[j]==s[top]){
					top=j;
					break;
				}
		    }
		}else vis[a[i]]=1;
		for(int j=head;j<=top;j++) mp[s[j]]++;
	}
	for(int i=1;i<=n;i++) cout <<mp[i]<<" ";
	
	return 0;
} 
