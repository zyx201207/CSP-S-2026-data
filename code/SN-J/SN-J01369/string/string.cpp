#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	int d=s.size()-1;
	int z=s.size()-1;
	int ans=s.size()/2;
	for(int i=0;i<d/2;i++){
		if(s[i]==s[z]){
			ans--;
		}
		z--;
	} 	
	cout<<ans;
	return 0;
}
