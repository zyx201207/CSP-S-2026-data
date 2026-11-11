#include<bits/stdc++.h>
using namespace std;
int n,ji=1;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x;
	char y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			s[ji]=y;
			ji++;
		}
	}
	ji--;
	long long ans=0;
	if(ji%2==0){
		for(int i=1;i<=ji/2;i++){
			s1[i]=s[i];
		}
		int jii=1;
		for(int i=ji;i>=(ji/2)+1;i--){
			s2[jii]=s[i];
			jii++;
		}
		for(int i=1;i<=ji/2;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=ji/2;i++){
			s1[i]=s[i];
		}
		int jii=1;
		for(int i=ji;i>=(ji/2)+2;i--){
			s2[jii]=s[i];
			jii++;
		}
		for(int i=1;i<=ji/2;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
