#include<bits/stdc++.h>
using namespace std;
int n;
int ar[200005];
char c[200005];
string s;
int h(string ss){
	int cnt=0;
	for(int i=0;i<(ss.size()-1)/2;i++){
		if(ss[i]!=ss[ss.size()-i-1]){
			cnt++;
		}
			
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i]>>c[i];
		for(int j=1;j<=ar[i];j++){
			s+=c[i];
		}
	}
	int ans=h(s);
	cout<<ans;
	return 0;
}