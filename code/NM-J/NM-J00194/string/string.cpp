#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int sum=0;
for(int i=1;i<=n;i++){
	string s;
	cin>>s;
	s=s[i]+s[i+1];
	int r=s.size()-1;
	int l=0;
	cin>>a;
	
	while(l!=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}
		else{
			sum++;
			l++;
			r--;
		}
	}
}
	if(sum==0){
		cout<<0;
	}
	else{
		cout<<sum;
	}
return 0;
}
