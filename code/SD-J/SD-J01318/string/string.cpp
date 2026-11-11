#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,l[N],r[N],ans,k;
char a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>a[i];
		r[i]=l[i];
		k+=l[i]%2;
	}
	int i=1,j=n;
	while(i<=n&&j>=1){
		if(r[j]<l[i]){
			if(a[j]!=a[i]){
				ans+=r[j];
			}
			l[i]-=r[j];
			j--;
		}
		else{
			if(a[j]!=a[i]){
				ans+=l[i];
			}
			r[j]-=l[i];
			i++;
		}
	}
	cout<<ans/2<<"\n";
	return 0;
}
/*
3
2 a
2 b
1 c



*/
