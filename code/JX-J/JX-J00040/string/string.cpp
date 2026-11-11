#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long cnt=0;
long long a;
char b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    while(n--){
		cin>>a>>b;
		//scanf("%d%c",&a,&b);
		while(a--)s+=b;
	}
	int len=s.size();
	for(int i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
    return 0;	
}
