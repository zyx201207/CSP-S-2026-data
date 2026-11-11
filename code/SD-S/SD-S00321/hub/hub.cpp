#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
inline int read(){
	char c=getchar();int ans=0,p=1;
	while (c<'0'||c>'9'){if (c=='-') p=-1;c=getchar();}
	while (c>='0'&&c<='9'){ans=ans*10+(c-48);c=getchar();}
	return ans*p;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while (t--){
		int n=read(),k=read();
		int l=1e9,li=1;
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			if (l>x){
				li=1;
				l=x;
			}else if (l==x){
				li++;
			}
		}
		cout<<li<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
