#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long int r=0;
	cin>>n;
    	string s=""; 
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		r+=a;
		char c;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	string ss="";
	string tt="";
	if(r%2==0){
		for(int i=0;i<r/2;i++){
			ss+=s[i];
		}
		for(int i=r-1;i>r/2-1;i--){
			tt+=s[i];
		}
		
	    int ans=0;
		if(ss==tt){
			cout<<'0';
		}else{
			for(int i=0;i<r/2;i++){
				if(ss[i]!=tt[i]){
					ans++;
				}
			}
			cout<<ans;
		}
		
	}else{
		for(int i=0;i<r/2;i++){
			ss+=s[i];
		}
		for(int i=r-1;i>r/2;i--){
			tt+=s[i];
		}
	    int ans=0;
		if(ss==tt){
			cout<<'0';
		}else{
			for(int i=0;i<r/2;i++){
				if(ss[i]!=tt[i]){
					ans++;
				}
			}
			cout<<ans;
		}
		
	}
	return 0;
}