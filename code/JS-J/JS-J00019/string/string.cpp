#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+78;
int a[N];char c[N],t[N];string s;
ll ans=0,boss;
int gg(int a,int b){
	if(a%b==0){
		return b;
	}else{
		gg(b,a%b);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	boss=2*a[0];
	for(int i=0;i<n;i++){
		boss=gg(boss,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i]/=boss;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-1-i]){
			break;
		}else{
			ans++;
		}
	}
	cout<<ans*boss;
	return 0;
}
