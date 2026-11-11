#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int nt[N];
int pr[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		nt[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		nt[i]=(i-1)*nt[i];
		pr[i]=nt[i]+pr[i-1];
	}
	int j=upper_bound(pr+1,pr+n+1,m)-pr;
	
	j--;
	if(pr[j]==m){
		cout<<j<<endl;
		return 0;
	}else{
		int ml=m-pr[j];
		for(int i=1;i<=ml/j;i++){
			if(a[j]+i==a[j+1]){
				cout<<j+1<<endl;
				return 0;
			}
		}
		cout<<j<<endl;
	}
	return 0;
}
