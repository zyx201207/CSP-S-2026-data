#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
long long n,m,c=1,a[MAXN],p[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); p[1]=0;
	for(int i=2;i<=n;i++){
		p[i]=(a[i]-a[i-1])*(i-1)+p[i-1];
		if(p[i]==m){c++;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]) c++;
				else break;
			}
			break;
		}
		else if(p[i]>m) break;
		else c++;
	}
	cout<<c;
	return 0;
}
