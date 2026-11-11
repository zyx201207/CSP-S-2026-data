#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,l=0,cs=0;
	char c;
	string s;
	string s_;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a>>c;
		s_+=c;
		for(int j=0;j<a;j++){
			s+=c;
			l++;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			cs++;
		}
	}
	printf("%d",cs);
	return 0;
}
