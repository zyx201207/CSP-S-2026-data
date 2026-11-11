#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	
	cin>>n;
	long long a,cnt=0;
	char c;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string ss="";
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
		int mm=s.size();
	if(ss==s){
		cout<<"0";
		return 0;
	}
	else{
		for(int i=0;i<(mm+1)/2;i++){
	if(s[i]!=ss[i]){
		cnt++;
	}
}

	cout<<cnt;
	}
	
	
	return 0;
} 
