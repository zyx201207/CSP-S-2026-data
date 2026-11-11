#include<bits/stdc++.h>
using namespace std;
string s;
string s1,s2;
long long num=0;
bool f(){
	string s0;
	int l=s.size()-1;
	for(int i=l;i>=0;i--){
		s0+=s[i];
	}
	if(s0==s)return 1;
	else return 0;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		} 
	}
	if(f()==1){
		cout<<num;
		return 0;
	}
	long long l=s.size()-1,l1=s.size();
	
	if(l1%2==1){
		for(int i=0;i<=l1/2-1;i++){
			s1+=s[i]; 
		}
		for(int i=l;i>=l1/2+1;i--){
			s2+=s[i];
		}
	}else{
		char k=l1/2,h=l1/2-1;
		if(k!=h)num++;
		for(int i=0;i<=l1/2-2;i++){
			s1+=s[i]; 
		}
		for(int i=l;i>=l1/2+1;i--){
			s2+=s[i];
		}
	}
	long long len=s1.size();
	for(int i=0;i<=len-1;i++){
		if(s1[i]!=s2[i])num++;
	}
	cout<<num;
	return 0;
} 
