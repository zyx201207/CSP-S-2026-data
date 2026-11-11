#include<bits/stdc++.h>
using namespace std;	
long long n,b;
string l,r;
string s,a;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);


	cin>>n;
	while(n--){
		cin>>b>>a;
		while(b--){
			s+=a;
		}
	}
	long long lo = s.size(),ans = 0;
	if(lo%2==0){
		for(int i = 0;i<lo/2;i++){
			l+=s[i];
		}
		for(int i = lo/2;i<lo;i++){
			r+=s[i];
		}
	}else{
		for(int i = 0;i<lo/2;i++){
			l+=s[i];
		}
		for(int i = lo/2+1;i<lo;i++){
			r+=s[i];
		}
	}
	//cout<<l<<" "<<r;
	reverse(r.begin(),r.end());
	for(int i = 0;i<l.size();i++){
		if(r[i]!=l[i]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}
