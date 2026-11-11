#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    long long cnt=0;
    for(int i=1;i<=n;i++){
    	long long a;
    	char c;
    	cin>>a>>c;
    	for(int j=1;j<=a;j++){
    		s[cnt]=c;
    		cnt++;
		}	
	}
	long long ans=0;
	long long l=0,r=cnt-1;
	while(l<r){
		if(s[l]!=s[r])
		    ans++;
		l++;
		r--;
	}
	cout<<ans;
    return 0;
}