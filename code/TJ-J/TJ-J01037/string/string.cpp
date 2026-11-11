#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,id,cnt;
struct node{
	long long a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	int i=1,f=-1;
	long long cha=0;
	while(i<=n){
		if(i==n&&s[i].a==1) break;
		if(s[i].a>s[n].a) f=1,cha=s[i].a-s[n].a;
		else if(s[i].a==s[n].a) f=3,cha=s[i].a-s[n].a;
		else f=2,cha=s[n].a-s[i].a;
		if(s[i].c!=s[n].c) cnt+=max(s[i].a,s[n].a)-cha;
		if(f==1) s[i].a-=cha,n--;
		if(f==2) s[n].a-=cha,i++;
		if(f==3) i++,n--;
	}
	cout<<cnt;
	return 0;
}
/* 
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
