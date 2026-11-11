#include<bits/stdc++.h>
using namespace std;

int n,ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	
	int l=(int)s.size()/2,i=0,j=(int)s.size()-1;
	while(i<l){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	
	return 0;
}

