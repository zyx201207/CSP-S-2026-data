#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string s1="";
	int l=s.size();
	for(int i=l-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}else{
		int cnt=0,k=l-1,r=1;
		while(s1!=s){
			s[k]=s[r];
			cnt++;
			s1="";
			for(int i=l-1;i>=0;i--){
				s1+=s[i];
			}
			k--;
			r++;
		}
		cout<<cnt;
		return 0;
	}
}
