#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++){
		int c;
		string b;
		cin>>c>>b;
		for(int j=1;j<=c;j++){
			a+=b;
		}
	}
	int r=a.size()-1,cc=0;
	int m=a.size()/2;
	for(int i=0;i<n;i++){
		int l=i;
		if(a[l]==a[r]){
			cc+=0;
		}
		else{
			cc+=1;
		}
		r--;
	}
	cout<<cc;
	return 0;
}
