#include <bits/stdc++.h>
using namespace std;
bool huiwen(string hw){
	long long n=hw.size();
	for(int i=0;i<n;i++){
		if(hw[i]!=hw[n-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,j=0;
	cin>>n;
	char cs[100005];
	for(int i=0;i<n;i++){
		long long g;
		cin>>g;
		char c;
		cin>>c;
		cs[i]=c;
		while(g!=0){
			s[j]=c;
			j++;
			g--;
		}
	}
	if(huiwen(s)==true){
		cout<<0;
	}else{
		for(long long i=0;i<s.size();i++){
			string sc=s;
			for(long long j=0;j<s.size();j++){
				for(long long z=0;z<n;z++){
					sc[j]=cs[z];
					if(huiwen(sc)){
						cout<<i+1;
					}
				}
			}
		}
	}
	return 0;
} 
