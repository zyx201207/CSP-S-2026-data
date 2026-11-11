#include<bits/stdc++.h>
using namespace std;
bool huiwen(string S){
	int l=0,r=S.size()-1,g=S.size()/2+1;
	while(g--){
		if(S[l]!=S[r]){
			return 0;
		}
		else{
			l++;
			r--;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,v,cc=0;
	cin>>n;
	char a;
	string s="";
	if(n==1){
		cout<<0;
		return 0;
	}
	while(n--){
		cin>>v>>a;
		for(int i=0;i<v;i++){
			s+=a;
		}
	}
	if(huiwen(s)==1) cout<<0;
	else{
		int l=0,r=s.size()-1,g=s.size()/2+1;
		while(g--){
			if(s[l]!=s[r]){
				s[r]=s[l];
				l++;
				r--;
				cc++;
				if(huiwen(s)){
					cout<<cc;
					return 0;
				}
			}
			else{
				l++;
				r--;
				if(huiwen(s)){
					cout<<cc;
					return 0;
				}
			}
		}
	}
	return 0;
}
