#include<bits/stdc++.h>
using namespace std;
int m,a[200000],ans; 
string s,z;
char b;
void fan(string x){
	int l=x.size();
	int le=l-1;
	for(int i=0;i<l;i++){
		z[le]=s[i];
		le--;
	} 
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.ans","w",stdout);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
		cin>>b;
		for(int i=0;i<a[i];i++){
			s[i]=b;
		}
	}
	fan(s);
	int ln=s.size()-1;

	for(int i=0;i<ln/2;i++){
		if(s[i]!=z[i]){
			ans++;
		}
		
	}
	cout<<ans;
}
