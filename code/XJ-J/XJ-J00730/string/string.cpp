#include<bits/stdc++.h>
using namespace std;
long long n,cnt,len,len1;//s的长度
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>a;
		for(int j=1;j<=len;j++){
			s+=a;
			len1++;
		}
	}
	int l=0,r=len1-1;
	while(r-l>=1){
		if(s[l]!=s[r]){
			cnt++;
			l++;
			r--;
		}else{
			l++;
			r--;	
		}
	}cout<<cnt;

	
	return 0;
}
