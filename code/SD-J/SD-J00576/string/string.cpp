#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
long long n,ans=0;
struct Node{
	long long a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&s[i].a,&s[i].c);
	}
	long long l=1,r=n;
	while(1){
		if(l>=r){
			break;
		}
		if(s[l].c==s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
				continue;
			}
			else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
				continue;
			}
			else if(s[l].a==s[r].a){
				r--;
				l++;
				continue;
			}
		}
		else{
			if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
				continue;
			}
			else if(s[l].a<s[r].a){
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
				continue;
			}
			else if(s[l].a==s[r].a){
				ans+=s[l].a;
				r--;
				l++;
				continue;
			}
		}
		if(s[l].a==0){
			l++;
		}
		if(s[r].a==0){
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
