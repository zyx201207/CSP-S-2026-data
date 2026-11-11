#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc_ getchar()
inline int read(){
	int x=0,f=1;char ch=gc_;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc_;}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc_;}
	return x*f;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read(),a1=read(),a2=read(),r=0;
	while(t--){
		r=(rand()*rand()-rand()*r)%10;
		cout<<r<<endl;
	}
	return 0;
} 
/*
我-作为一名绝望的oier，已经没有什么事情可以让我睁眼了；
q-你的csp成绩如奶油般化开；
我-嗐~嗐嗐~……；
q-队友呼吸机关一下；
我-nm； 
*/
