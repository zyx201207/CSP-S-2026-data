#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i= 1;i<=n;i++){
		long long m;
		cin>>m;
		char c;
		cin>>c;
		for(int j = 1;j<=m;j++){
			s+=c;
		}
	}
	long long h = 0;
	long long d = s.size();
	for(int i= 0;i<d/2;i++){
		if(s[i]!=s[d-1-i]){
			h++;
			cout<<s[i]<<" "<<s[d-1-i]<<endl;
		}
	}
	cout<<h;
	return 0;
}

