//Trick||Treat!
#include<bits/stdc++.h>
#define LLU unsigned long long
using namespace std;
const LLU MAXN=2e5+5;
struct str{
    LLU num;
    char c;
}s[MAXN];
LLU n,ans=0;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%llu",&n);
	for(int i=1;i<=n;++i){
		scanf("%llu %c",&s[i].num,&s[i].c);
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].num>s[r].num){
				s[l].num-=s[r].num;
				r--;
			}
			else if(s[l].num<s[r].num){
				s[r].num-=s[l].num;
				l++;
			}
			else if(s[l].num==s[r].num){
				r--;l++;
			}
		}
		else if(s[l].c!=s[r].c){
			if(s[l].num>s[r].num){
				ans+=s[l].num-s[r].num;
				s[l].num-=s[r].num;
				r--;
			}
			else if(s[l].num<s[r].num){
				ans+=s[r].num-s[l].num;
				s[r].num-=s[l].num;
				l++;
			}
			else if(s[l].num==s[r].num){
				ans+=s[r].num;
				r--;l++;
			}
		}
	}
	printf("%llu",ans);
	return 0;
}
