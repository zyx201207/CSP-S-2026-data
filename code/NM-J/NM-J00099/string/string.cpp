#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;//循环结束不用了 
long long b;//到哪了 
char c;
string ans;
string san;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;  
    for(int i=1;i<=n;i++){
    	cin>>a;//几个 
    	b+=a;
    	cin>>c;//什么 
    	for(int j=1;j<=a;j++) ans+=c;
	}
	for(int i=0;i<=b/2-1;i++){
		if(ans[i]!=ans[b-1]) cnt++;
	}
    cout<<cnt;
    return 0;
}
