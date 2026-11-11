#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	int cur;
	string s,s1;
	cin>>n;
	while(n--){
		cin>>cur;
		cin>>s1;
		for(int i=0;i<cur;i++) s+=s1;
	}
	string s2;
	int s2_num=0;
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++) s2[i]=s[i];
		for(int i=s.size()/2;i<s.size();i++) if(s[i]!=s2[s2_num++]) ans++;
	}else{
		for(int i=0;i<s.size()/2;i++) s2[i]=s[i];
		for(int i=s.size()/2+1;i<s.size();i++) if(s[i]!=s2[s2_num++]) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
