#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n,a,sum=0;
	char c;
	cin>>n;
	string s,s1,s2;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	if(s.size()%2!=0){
		for(int i=0;i<s.size()/2;++i){
			s1+=s[i];
		}
		for(int j=s.size()-1;j>=s.size()/2+1;--j){
			s2+=s[j];
		}
		if(s1==s2){
			cout<<0<<endl;
		}
		else{
			for(int i=0;i<s.size()/2;i++){
				if(s1[i]==s2[i]){
					break;
				}
				else{
					sum++;
				}
			}
			cout<<sum;
		}
	}
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2+1;++i){
			s1+=s[i];
		}
		for(int i=s.size()-1;i>=s.size()/2;--i){
			s2+=s[i];
		}
		if(s1==s2){
			cout<<0<<endl;
		}
		else{
			for(int i=0;i<s.size()/2;i++){
				if(s1[i]==s2[i]){
					break;
				}
				else{
					sum++;
				}
			}
			cout<<sum;
		}
	}
	
	return 0;
}