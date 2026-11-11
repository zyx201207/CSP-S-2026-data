#include<bits/stdc++.h>

using namespace std;

string s;

int main(){
	//freopen("string.in","r",stdin);
	//qfreopen("string.out","w",stdout);
	long long n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		long m;
		char c;
		scanf("%d",&m);
		scanf("%s",&c);
		for(long long j=0;j<m;++j){
			s=s+c;
		}
	} 
	long long len=s.size(),l=len,cnt=0,f=0;
	while(true){
		if(s[f]==s[len-f-1]){
			l-=2;
			f++;
		}else{
			s[len-f-1]=s[f];
			l-2;
			cnt++;
			f++;
		}
		if(l==1||l==0)break;
	}
	printf("%d",cnt);

	return 0;
} /*
6
100000 a
100000 a
100000 a
100000 b
100000 b
100000 b
*/
