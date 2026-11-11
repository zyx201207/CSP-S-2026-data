#include<bits/stdc++.h>
using namespace std;
int n,b[2000005],cnt=0;
string s,x,y;
string a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>a[i];
		for(int j=0;j<b[i];j++){
			s+=a[i];
		}
	}
	for(int i=s.size();i>=0;i--){
		x+=s[i];
	}
	if(n==1||(a[0]==a[1]))cout<<0;
	else cout<<min(b[0],b[1]);
	return 0;
}
