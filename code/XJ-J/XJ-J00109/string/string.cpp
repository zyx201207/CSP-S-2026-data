#include<bits/stdc++.h>
using namespace std;
long long int n,l,sl;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		l+=a;
	}
	for(int i=0,j=l-1;i<l/2,j>l-(l/2)-1;i++,j--){
		s1+=s[i];
		s2+=s[j];
	}
	long long int cnt=0;
	for(int i=0;i<l/2;i++){
		if(s1[i]!=s2[i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
