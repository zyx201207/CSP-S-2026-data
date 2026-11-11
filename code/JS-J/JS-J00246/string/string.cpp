#include <bits/stdc++.h>
using namespace std;
long long n,a1,x=1,ans;
char c1,s[2222222];
bool f;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a1>>c1;
		for(int j=1;j<=a1;j++){
			s[x]=c1;
			x++;
			}
		}
	long long l=1,r=x-1;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
			f=true;
			}
		else{
			f=false;
			ans++;
			l++;
			r--;
			}
		}
	cout<<ans;
    return 0;
}
