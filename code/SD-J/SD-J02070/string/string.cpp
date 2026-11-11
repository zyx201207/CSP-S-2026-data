#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
char c[N];
string s=" ";
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}n=s.size()-1;
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n-i+1])ans++;
	}cout<<ans;
	
	
	return 0;
} 
