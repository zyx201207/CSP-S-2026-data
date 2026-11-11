#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]and s[j] > maxn) maxn= s[i]and s[j];
		}
	}
	cout<<maxn;
	return 0;
}
