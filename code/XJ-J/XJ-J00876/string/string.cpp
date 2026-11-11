#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,size,cut,ans;
	long long num;
	string s,c;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>num>>c;
		for(int j=0;j<num;j++){
			s+=c;
		}
	}
	
	size=(int)s.size();
	
	if(size%2==0){
		cut=size/2;
		for(int m=0;m<cut;++m){
			if(s[m]==s[size-1-m]){
				ans+=0;
			}
			else{
				ans+=1;
			}
		}
	}
	else{
		cut=size/2+1;
		for(int n=0;n<cut-1;++n){
			if(s[0]==s[size-1-n]){
				ans+=0;
			}
			else{
				ans+=1;
			}
		}
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}
