#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    long long L=0;
    for(int i=1;i<=n;i++){
    	int l;
    	char c;
    	cin>>l>>c;
    	L+=l;
    	for(int j=1;j<=l;j++){
    		s+=c;
		}
	}
	int cnt=0;
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
