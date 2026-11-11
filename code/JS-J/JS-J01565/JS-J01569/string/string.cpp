#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int a;
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    for(int i=0,j=s.length()-1;i<s.length()/2;i++){
        if(s[i]!=s[j]){
            ans++;
        }j--;
    }cout<<ans;
	return 0;
}
