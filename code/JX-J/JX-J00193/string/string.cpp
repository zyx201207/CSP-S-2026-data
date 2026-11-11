#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        while(a--)s+=b;
	}
	long long ans=0;
	long long l=s.size();
	for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
