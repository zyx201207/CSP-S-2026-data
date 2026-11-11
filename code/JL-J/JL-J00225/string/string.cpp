#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,c;
int n,a[N],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=a[i];j>0;j--){
			s[a[i-1]+a[i]-j+1]=c[i];
		}
	}if(s.length()%2==0){
	for(int i=0;i<s.length()/2;i++){
		if(s[s.length()/2-i]!=s[s.length()/2+i]){
			ans++;
		}
	}}else {
		for(int i=0;i<s.length()/2;i++){
			if(s[s.length()/2-i]!=s[s.length()/2+1+i]){
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}
