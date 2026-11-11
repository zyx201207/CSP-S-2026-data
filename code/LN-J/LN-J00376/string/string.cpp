#include<bits/stdc++.h>
using namespace std;
int n,ans,len;
string s;
signed main(){
    
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin>>n;
    for(int i=0;i<n;i++){
	int foo;
	char bar;
	cin>>foo>>bar;
	for(int i=0;i<foo;i++) s+=bar;
	len+=foo;
    }
    //cout<<s<<endl;
    for(int i=0;i<len-1;i++){
	if(s[i]!=s[len-i-1]){
		//cout<<i<<':'<<s[i]<<' '<<len-i-1<<":"<<s[len-i-1]<<endl;
		ans++;
	}
    }
    cout<<(ans>>1)<<endl;
}
