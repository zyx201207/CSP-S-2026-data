#include<bits/stdc++.h>
using namespace std;
int n,x,cnt;
char c;
string s="";
vector <int>v; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
