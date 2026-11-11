#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,b[N],ans;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> b[i] >> a[i];
	}
	ll p=1,t=n,sum;
	while(p<t){
		sum = min(b[p],b[t]);
		if(a[p]==a[t]){
			b[p]-=sum;
			b[t]-=sum;
		}
		else{
			b[p]-=sum;
			b[t]-=sum;
			ans+=sum;
		}
		if(b[p]==0) p++;
		if(b[t]==0) t--;
	}
	cout << ans;
	return 0;
	
} 
