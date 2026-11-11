#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);*/
	
	long long  s1,n,cnt=0;
	char a1;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s1>>a1;
		for(int j=1;j<=s1;j++) s+=a1;
	}
	int l=1,r=s.size();
	while(l<=r){
		if(s[l]!=s[r])cnt++;
		l++,r--;
	}	
	cout<<cnt;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}