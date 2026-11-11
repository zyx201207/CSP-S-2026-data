#include<bits/stdc++.h>
using namespace std;
string lia,lib,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>lia>>sa>>lib>>sb;
	for(int i=0;i<2;i++){
		if(lia[i]!=lib[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(sa[i]!=sb[i]){
			cout<<"1000";
			return 0;
		}
	}
	bool s1=0,s2=0;
	if(sa[2]<='F'&&sa[2]>='D'){
		s1=1;
	}
	if(sb[2]<='F'&&sb[2]>='D'){
		s2=1;
	}
	if(s1!=s2){
		cout<<"1100";
		return 0;
	}
	if(sa[2]-1!=sb[2]&&sa[2]+1!=sb[2]){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
