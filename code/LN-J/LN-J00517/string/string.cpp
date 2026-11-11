#include<bits/stdc++.h>
using namespace std;
long long l,n,cnt;
char s[1000000000];
void check(){
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]){ 
			cnt++;
			//cout<<s[i]<<s[l-1-i]<<'\n';
		}
    }
    cout<<cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int n;
        char c;
        cin>>n>>c;
        for(int i=0;i<n;i++){
            s[i+l]+=c;
        }
        l+=n;
    }
    //cout<<l<<'\n';
    check();
    return 0;
}

