#include<bits/stdc++.h>
using namespace std;
int n,t;
string s;
char a;
int m;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>a;
		for(int j=0;j<t;j++){
			s+=a;
		}
	}
	//cout<<s;
	int l=s.size();
	//cout<<l<<s[5]<<endl;
	if(l%2==1){
		s[l+1]=s[1];
	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i]){
			s[l-i]=s[i];
			//cout<<i<<" "<<l-i;
			cnt++;
		}
	}
	cout<<cnt;


	return 0;
}
