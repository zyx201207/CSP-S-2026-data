#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,c=0;
bool hw(){
	for(int i=0;i<=s.size()-1;i++){
		t=s[i]+t;
	}
	if(t==s){
		return true;
	}else{
		return false;
	}
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	int z;
		string a;
    	cin>>z>>a;
    	for(int i=1;i<=z;i++){
    		s=s+a;
		}
	}
	if(hw()==true){
		cout<<'0';
		return 0;
	}else{
		for(int i=0;i<=s.size()/2;i++){
			if(s[i]!=t[i]){
				c++;
			}
		}
	}
	cout<<c<<" ";

    return 0;
}
