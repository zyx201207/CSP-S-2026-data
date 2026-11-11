#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1001]={},ans,j=0,l,w;
	char c;
	vector<char>v;
	string f;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(j=0;j<a[i];j++){
			v.push_back(c);
			l==c;
			w==c;	
		}
	}
	for(int i=0;i<n;i++){
		if(v[i-l]==v[i-w]){
			cout<<0;
		}
		if(v[i-l]!=v[i-w]){
			v[i]==c;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}



