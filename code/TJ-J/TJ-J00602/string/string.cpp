#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s="";
    int n,x,ans=0;
    char y;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x;
    	cin>>y;
    	while(x--){
    		s+=y;
		}
	}
	string s_1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s_1[i])ans++;
	}
	cout<<ans;
	return 0;
}
