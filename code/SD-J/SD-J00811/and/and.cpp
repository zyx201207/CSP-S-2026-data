#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[222222],ma,sum;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=1;
		while(j*2<=a[i]){
			j*=2;
		}
		ma=max(ma,j);
	}
	sort(a+1,a+1+n,cmp);
	//cout<<ma<<endl<<a[1]<<endl;
	for(int j=ma;j>=1;j/=2){
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=j){
				a[i]-=j;
			}else{
				if(i-1>=m){
					sum+=j;
					n=i-1;
				}
				f=1;
				break;
			}
		}
		if(f==0) sum+=j;
		sort(a+1,a+1+n,cmp);
	}
	cout<<sum;
	return 0;
}
/*
1111
1100
1100
0011


*/

/*
10000
01110
01101

16
14
13
*/

/*
11111
10101
10101
10000
00100
00010
00001
00000

11111
10101
10101
10000
00100
00010
00001
00000
*/
