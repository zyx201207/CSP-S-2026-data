#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,sum;
char c;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(ll i=1;i<=a;i++){
			s+=c;
		}
	}
	for(ll i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	for(ll i=0;i<s.size();i++){
		if(s[i]!=s2[i]){
			sum++;
		} 
	}
	cout<<sum/2;
	return 0;
}
//阴间题目(2).cpp
//关于我T2行数是T1的一半这件事 
