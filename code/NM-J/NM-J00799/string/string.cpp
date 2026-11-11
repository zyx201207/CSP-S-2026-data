#include<bits/stdc++.h>
using namespace std;
long long n,op,cnt1,cnt2,cnt3;
string s, zc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>zc;
		while(op--)s+=zc;
	}
	op=s.size();
	for(int i=0;i<=(op-1)/2;i++){
		if(s[i]!=s[op-1-i]){
			if(cnt1>=2100000000){
				cnt2++;
			}
			else cnt1++;
    	}
	}
	cout<<cnt1+cnt2;
	return 0;
}
