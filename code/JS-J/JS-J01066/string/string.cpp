#include<bits/stdc++.h>
using namespace std;
int n;long long a,ans=0;
string s;char w;
int main(){
	 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>w;
		for(int i=0;i<a;i++)s+=w;
	}
	 
	long long l=s.size();
	for(int i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-i-1]){ans++;}
		
	}
	cout<<ans;
	
	
	
	return 0;
}
