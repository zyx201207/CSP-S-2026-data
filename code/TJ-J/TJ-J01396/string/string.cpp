#include<bits/stdc++.h>
using namespace std;
//guodedaima
struct node{
	long long a;
	char c;
}s[200005];
string ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s[i].a>>s[i].c;
	}
	for(int i=1;i<=n;i++){
		ans+=string(s[i].a,s[i].c);
	}
    long long l=0,r=ans.size()-1,cnt=0;
	while(l<=r){
		if(ans[l]!=ans[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}