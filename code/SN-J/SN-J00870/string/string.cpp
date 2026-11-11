#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n,a,m=0;
	long long ans=0,ans1=0;
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++)s+=c;
		m+=a;
	}
	//cout<<s;
	if(n%2==0){ 
		int f=m/2;
		for(int i=0;i<m/2;i++){
			if(s[i]!=s[f-1-i+f])ans++;
		}
		for(int i=m-1;i>=m/2;i--){
			if(s[i]!=s[f-1-(i-f)])ans1++;
		}
	}
	else {
		int f=m/2;
		for(int i=0;i<m/2;i++){
			if(s[i]!=s[f-i+f])ans++;
		}
		for(int i=m-1;i>=m/2;i--){
			if(s[i]!=s[f-(i-f)])ans1++;
		}
	}
	cout<<min(ans,ans1);
	
	return 0;
}
