#include<iostream>
using namespace std;
int n;char c;
long long a,cnt;
string s;
string build(int a,char c){
	string ans;
	while(a!=0){ans+=c;a--;}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;s+=build(a,c);
	}
	for(long long i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
}
