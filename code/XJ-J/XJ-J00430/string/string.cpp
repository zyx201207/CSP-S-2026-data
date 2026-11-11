#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,w=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		string c;
		int a;
		cin>>a>>c;
		w+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int z=w,he=0;
	w/=2;
	for(int i=0,j=z-1;i<w;i++,j--){
		if(s[i]!=s[j]){
			he++;
		}
	}
	cout<<he;
	return 0;
}