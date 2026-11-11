#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000001],er[100000000000001],cnt;
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		er[i]+=a[i]%2;
		for(int l=1;l<=s.size();l++){
		for(int r=s.size();r>=1;r--){
			if(s[r]!=s[l]){
				cnt++;
			}
		}
	}
	}
	cout<<a[3];
	return 0;
}