#include<bits/stdc++.h>
using namespace std;

inline void rd(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t;
	rd(t);
	for(int i=1;i<=t;i++){
		cout<<rand()<<endl;
	}
	return 0;
}
