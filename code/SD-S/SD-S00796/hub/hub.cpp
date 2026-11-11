#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
void solve() {
	cout<<"Maybe I cannot meet you again."<<endl;
	cout<<"So, I'm willing to enjoy the time with you than everything."<<endl;
	cout<<"Maybe I cannot meet you again."<<endl;
	cout<<"So, I'm satisfied to take part in everything you tried."<<endl;
	cout<<"Maybe I cannot meet you again."<<endl;
	cout<<"So, I'm frightened at night without you."<<endl;
	cout<<"Maybe I cannot meet you again."<<endl;
	cout<<"So, could you give me another choice in next exam?"<<endl;
	cout<<"Oh, there will be not my code in next exam."<<endl;
	cout<<"There will be not me in next exam."<<endl;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c=read(),T=read();
	solve();
	return 0;
}
