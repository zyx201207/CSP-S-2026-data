#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
string s;
bool x=true;
string a;
unsigned long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		long long z;
		string y;
		cin>>z>>y;
		for(int i=1;i<=z;i++){
			s+=y;
		}
		if(a[0]!=y[0])x=false;
		a=y;
	}
	if(x){
		cout<<"0";return 0;
	}
	string s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s1[i]!=s[i])ans++;
	} 
	cout<<ans/2;
	return 0;
}
