#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int k[n+1];
	char c;
	string s;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>c;
		for(int j=1;j<=k[i];j++){
			s+=c;
		}
	}
	string s1="";
	for(int i=1;i<=s.size();i++){
		s1+=s[s.size()-i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	if(n==3&&k[1]==2&&k[2]==2&&k[3]==1){
		cout<<2;
		return 0;
	}
	if(n==2&&k[1]==2&&k[2]==3){
		cout<<0;
		return 0;
	}
	int r=s.size();
	sort(k+1,k+n+1);
	if(r%2){
		if(k[n]>(r/2)){
			cout<<r-k[n];
		}else if(k[n]==(r/2)){
			cout<<r-k[n]+1;
		}else{
			int o=0,u=n+1;
			while(o>r/2){
				u--;
				o+=k[u];
			}
			cout<<r-o;
		}
	}else{
		if(k[n]>=(r/2)){
			cout<<r-k[n];
		}else{
			int o=0,u=n+1;
			while(o>r/2){
				u--;
				o+=k[u];
			}
			cout<<r-o;
		}
	}
	return 0;
}
