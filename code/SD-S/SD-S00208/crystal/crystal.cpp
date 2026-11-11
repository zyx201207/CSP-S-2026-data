#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int mx=1;
	//1 6 7 9 14 25   15
	int besti=-1e9,bestj=-1e9,besttempm=-1e9;
	for (int i=n;i>=1;i--)//´ÓÓÒ±ßÄÄÀï¿ªÊ¼Íù×óÊÔ
	{
		for (int j=i-1;j>=1;j--)//Íù×óÊÔ 
		{
			int tmpm=((i-j+1)*a[i])-(sum[i]-sum[j-1]);
			if (tmpm>m)	break;
			else{
				if (i-j+1>mx){
					mx=i-j+1;
//					besti=i;
//					bestj=j;
//					besttempm=tmpm;
				}
				
			}
				
		}
	 } 
	cout << mx ;
	return 0;
}
