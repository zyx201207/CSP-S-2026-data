#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	string s;
	int t;
	cin>>t;
	while(t--){
		int x;
		char op;
		cin>>x;
		cin>>op;
		while(x--){
			s+=op;
		}
	}
	int lens=s.size();
	string c=s;
	reverse(s.begin(),s.end());
	int sum=0;
	for(int i=0;i<=lens-1;i++){
		if(s[i]!=c[i]){
			sum++;
		} 
	}
	cout<<sum/2;
	return 0; 
} 
