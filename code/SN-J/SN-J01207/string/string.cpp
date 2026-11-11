#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a,ans;
char b; 
string s;
void fill(int i){
	cin>>a>>b;
	for(int i=0;i<a;i++){
		s+=b;
	}
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	
	cin>>n;
	for(int i=0;i<n;i++)  fill(i);
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			//cout<<"["<<i<<"]"<<s[i]<<" "<<s[s.size()-i-1]<<"\n";
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
