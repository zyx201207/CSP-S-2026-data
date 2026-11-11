#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int H=1e8+10;
ll n,a[H];
char s;
bool check(string a){
	string b;
	b=a;
	reverse(b.begin(),b.end());
	return if(a==b);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    string x;
	    cin>>a[i]>>x;
	    for(int j=1;j<=a[i];j++){
	    	s+=x;
		}
	}
	if(s.size()==1){
    	cout<<0;
	}else if(check(s)){
		if(s.size()==2){
			cout<<1;
		}
	}
	return 0;
}