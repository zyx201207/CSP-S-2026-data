#include<bits/stdc++.h>
using namespace std;
long long ans,len;
int n;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long T;
		char c;
		scanf("%lld %c",&T,&c);
		len=len+T; 
		while(T--){
			str=str+c;
		}
	}
	len--;
	for(int i=0;i<=len/2;i++){
		if(str[i]!=str[len-i]) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
