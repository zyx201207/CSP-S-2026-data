#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string p,q,vv,vb;
	long long n,xyy=0;
	cin>>n;
	long long b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
		cin>>q[i];
		for(int j=0;j<b[i];j++){
			p+=q[i];
		}
	}
	for(int i=0;i<p.length()/2;i++){
		vv+=p[i];
	}
	for(int i=p.length()-1;i>p.length()/2;i--){
		vb+=p[i];
	}
	for(int i=0;i<p.length();i++){
		if(vv[i]!=vb[i]){
			xyy+=1;
		}
	}
	cout<<xyy;
}