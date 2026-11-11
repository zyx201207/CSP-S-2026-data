#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],ans,difference=0;
string s;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		string b;
		cin>>a[i]>>b;
		for(int j=0;j<a[i];j++) s+=b;
		ans+=a[i];
	} 
	for(int j=0;j<ans/2;j++){
		if(s[j]!=s[ans-1-j]){
			difference++;
		} 
	}
	cout<<difference;
	return 0;
}
