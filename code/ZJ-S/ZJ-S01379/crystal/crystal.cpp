#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

long long a[N];
long long n,m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+1+n);
	int l=1,r=1,mx=0,sum=1;
	bool flag=0;
	unsigned long long cnt=0;
	int p=0;
	while(1){
		if(r==n+1||l>n)break;
//		cout<<l<<" "<<r<<" "<<sum<<" "<<cnt<<" "<<m<<"\n";
//		if(p==10)return 0;
		
		if(r!=1&&!flag)cnt=cnt+(r-l)*(a[r]-a[r-1]),flag=1;
		if(cnt>m){l++,sum--,cnt=cnt-(a[r]-a[l-1]),p++;/*cout<<a[l-1]<<" "<<a[r]<<" "<<cnt<<"\n";return 0;*/}
		else mx=max(mx,sum),r++,sum++,flag=0;
	}
	cout<<mx;
	return 0;
}

/*

15:09:57

er fen->chi qu

100pts



5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
