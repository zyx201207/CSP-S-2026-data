#include<bits/stdc++.h>
using namespace std;
string s;
long long n,len,r,l,ans,op;
char c;
void Insert(long long op,char c){
	while(op--) s=s+c;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %c",&op,&c);
		Insert(op,c);
		len+=op;
	}
	r=len-1;
	for(int i=1;i<=(len+1)/2;i++){
		if(s[l]!=s[r]) ans++;
		l++;r--;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
