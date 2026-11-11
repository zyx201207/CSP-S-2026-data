#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int n,a;
char c;
string s;
LL ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false); 
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
