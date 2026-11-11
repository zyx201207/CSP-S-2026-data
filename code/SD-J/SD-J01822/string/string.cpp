# include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<((int)s.size()+1)/2;i++){
		if(s[i]!=s[n-i+1]){
			s[i]=s[n-i+1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
