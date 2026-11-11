#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum;
int n,a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	ll l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			sum++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}