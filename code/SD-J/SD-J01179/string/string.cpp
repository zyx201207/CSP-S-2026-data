#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char a[N],c[N];
unsigned long long t,n,cnt=1,sum,b[N],cnt1=0;
signed main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		for(int j=cnt1;j<=cnt1+b[i];j++){
			a[j]=c[i];
			
		}
		cnt1+=b[i];
	}
	for(int i=cnt1/2;i>=1;i--){
		if(a[i]!=a[cnt]){
			sum++;
		}
		cnt++;
	}
	cout<<sum;
	return 0;
}
