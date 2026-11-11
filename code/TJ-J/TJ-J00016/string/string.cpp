#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	char c;
	long long b;
};
node a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		cin>>a[i].c;
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].b;j++){
			s+=a[i].c;
		} 
	}
	string s2,s3;
	for(int i=0;i<=(s.size())/2;i++){
		s2+=s[i];
	}
	for(int i=s.size()-1;i>=(s.size()-1)/2;i--){
		s3+=s[i];
	}
	for(int i=0;i<=s2.size()-1;i++){
		if(s2[i]!=s3[i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
} 
