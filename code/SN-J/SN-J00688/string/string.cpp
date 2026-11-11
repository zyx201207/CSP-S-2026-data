//陈润坤 西安市一中 SN-J00688 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s,s1;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		s1=s;
		reverse(s.begin(),s.end());
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
