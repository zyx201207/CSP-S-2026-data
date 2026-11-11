#include<bits/stdc++.h>
using namespace std;
long long a[100000000005];
int n,sum=0;
char c;
string s="",hs="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	int l=s.size();
	if(l%2==0){
		for(int i=0;i<=l/2;i++){
			hs+=s[i];
		}	
		for(int i=l/2;i>=0;i--){
			hs+=s[i];
		}	
	}else{
		for(int i=0;i<l/2+1;i++){
			hs+=s[i];
		}
		for(int i=l/2-1;i>=0;i--){
			hs+=hs[i];
		}
	}
	for(int i=1;i<=l;i++){
		if(s[i]!=hs[i]){
			sum++;
		}
	}
	if(l%2==0)cout<<sum-1;
	else cout<<sum;
	return 0;
}