#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,q;
	long long n,a,p=1,c,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>q;
		for(int i=1;i<=a;i++){
			s+=q;
		}
	}
	c=s.size();
	for(int i=0;i<c-1;i++){
		if(s[i]!=s[i+1]) p=0;
	}
	if(p==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=c/2-1;i++){
		if(s[i]!=s[c-1-i]) m++;
	}
	cout<<m;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
