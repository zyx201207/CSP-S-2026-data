#include<bits/stdc++.h>
using namespace std;
int n;
string ch;
long long len=0;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		long long x;
		char a;
		cin>>x>>a;
		string t=string(x,a);
		ch+=t;
		len+=x;
	}	
	for(long long i=0,j=len-1-i;i<=j;i++,j--){
		if(ch[i]!=ch[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
