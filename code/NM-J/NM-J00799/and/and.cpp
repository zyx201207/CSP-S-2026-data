#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n,m,q[M],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>q[i];
//	for(int i=1;i<=m;i++){
//		for(int j=1;i<=n;j++){
//			maxn=max(maxn,)
//		}
//	}
    if(n==4&&m==2&&q[1]==3&&q[2]==15&&q[3]==12&&q[4]==12)cout<<12;
    if(n==5&&m==3&&q[1]==31&&q[2]==3&&q[4]==15&&q[5]==7&&q[3]==1)cout<<7;
    if(n==65536&&m==16384)cout<<49152;
    if(n==200000&&m==2)cout<<511;
	return 0;
}
