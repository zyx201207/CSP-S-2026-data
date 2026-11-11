#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
char ch[N];
long long cnt=0;
int main(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		int n;
		cin>>n;
		int a;
		char c;
		for(int i=1;i<=n;i++){
			cin>>a>>c;
			for(int j=1;j<=a;j++){
				ch[++cnt]=c;
			}
		}
		long long xht=0;
		for(int i=1;i<=cnt/2;i++){
			if(ch[i]!=ch[cnt-i+1])	xht++;
		}
		printf("%lld",xht);
		return 0;
		//baoli
}
