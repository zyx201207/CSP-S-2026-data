#include<bits/stdc++.h>
using namespace std;
int n;
string a="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		char d;
		cin>>m>>d;
		for(int i=0;i<m;i++){
			a+=d;
		}
	}
	int ans=0;
	for(int i=(a.size()+1)/2;i<a.size();i++){
		if(a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
