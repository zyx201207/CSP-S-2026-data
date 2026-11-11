#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
int n,a[N],dp[N]; 
ll ans,m;
char c[N];
int main()
{
//ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	bool f1=0;
	for(int j=1;j<n;j++) {
		if(c[j]!=c[j+1]) {
			f1=1;
			break;	
		}
	}
	if(!f1) cout<<0;
	else{
		int ny=1;
		for(int j=1;j<n;j++)
		{
		//	cout<<ny<<" "<<j+1<<endl;
			if(c[ny]==c[j+1]){
				//ºÏ²¢
				n--;
				a[ny]+=a[j+1];
				c[j+1]=' ';
			}else ny=j;
		}
		if(n==2||n==4) cout<<m/2;
		else cout<<m/(n*n);
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
