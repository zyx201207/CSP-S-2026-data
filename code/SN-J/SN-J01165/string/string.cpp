#include<bits/stdc++.h>
using namespace std;
long long n,a;
long long ans=0;
string b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	long long l,r;
	if(s.size()/2==0){
		l=s[s.size()/2];
		r=s[s.size()/2];
		for(int i=1;i<=s.size();i++){
			l--;
			if(l!=r){
			r++;
				ans++;
			}else{
				i++;
			}
		}
	}else{
		l=s[(s.size()-1)/2];
		r=s[(s.size()-1)/2+1];
		for(int i=1;i<=(s.size()-1)/2;i++){
			l--;
			r++;
			if(l!=r){
				ans++;
			}else{
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
