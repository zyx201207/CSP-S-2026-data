#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n;
long long len=0,ans=0;
long long a[N],sum[N],s[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		len+=a[i];
		sum[i]=len;
	}
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+a[i];
	}
	long long x=0,y=0,xp=1,yp=n;
	while(xp<=n && yp>=1){
		if(c[xp]!=c[yp]){
			if(sum[xp]>=s[yp]){
				ans+=s[yp]-x;
//				cout << yp << " " << y <<" y" << s[yp]-x << endl;
				x=s[yp];
				y=s[yp];
				
				yp--;
			}
			else{
				ans+=sum[xp]-y;
//				cout << xp << " " << x <<" x" << sum[xp]-y <<endl;
				x=sum[xp];
				y=sum[xp];
				xp++;
			}			
		}
		else{
			if(sum[xp]>=s[yp]){
				x=s[yp];
				y=s[yp];
				yp--;
			}
			else{
				x=sum[xp];
				y=sum[xp];
				xp++;
			}
		}
	}
	cout << ans/2 << endl;
	return 0;
}

