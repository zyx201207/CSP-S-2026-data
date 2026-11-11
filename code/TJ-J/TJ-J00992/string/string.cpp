#include<bits/stdc++.h>
using namespace std;
string s,s1;
int ans,ans1,a;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a>>b;
		for(int j=1; j<=a; j++){
			s[++ans]=b;
		}
	}
	for(int i=ans; i>=1; i--){
		s1[++ans1]=s[i];
	}
	int cnt=0;
	for(int i=1; i<=ans; i++){
		if(s1[i]!=s[i]){
			s1[i]=s[i];
			s[ans-i+1]=s[i];
			cnt++;
		}
	}
	cout<<cnt<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
