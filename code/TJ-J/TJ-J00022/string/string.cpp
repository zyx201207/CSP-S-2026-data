#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	int x=0;
	cin>>n;
	vector<int> a(n,0);
	vector<char> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		x+=a[i];
	}
	vector<char> o(x);
	int h=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			o[h]=b[i];
			h++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=0,r=x-1;
	while(l<=r){
		if(o[l]!=o[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
