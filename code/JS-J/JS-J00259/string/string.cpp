#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s2+=c;
		}
	}
	s1=s2;
	int l=s1.size();
	for(int q=0,p=l-1;q<l,p>=0;q++,p--){
		s2[q]=s1[p];
	}
	if(s1==s2){
		cout<<0;
		return 0;
	}
	for(int i=0;i<l;i++){
		s1[i]=s2[i];
		ans++;
		s2=s1;
		int l=s1.size();
		for(int q=0,p=l-1;q<l,p>=0;q++,p--){
			s2[q]=s1[p];
		}
		if(s1==s2){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
