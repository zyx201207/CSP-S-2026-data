#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cc=0;
	long long k;
	char c;
	string s="",s2="";
	cin>>n;
	int k3,k4;
	char c3,c4;
	if(n==1){
		cin>>k3>>c3;
		cout<<"0";
		return 0;
	}
	if(n==2){
		cin>>k3>>c3>>k4>>c4;
		if(c3==c4){
			cout<<"0";
			return 0;
		}
		if(k3==k4){
			cout<<"0";
			return 0;
		}
		if(k3<k4){
			cout<<k3;
			return 0;
		}
		if(k3>k4){
			cout<<k4;
			return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>k>>c;
			for(int j=1;j<=k;j++){
				s+=c;
			}
			if(k==1){
				cc++;
			}
		}
		if(cc==n){
			cout<<(n-1)/2;
			return 0;
		}
		else{
			for(int i=s.size()-1;i>=0;i--){
				s2+=s[i];
			}
			if(s==s2){
				cout<<"0";
				return 0;
			}
			return 0;	
		}
		
	}
	
}

