//有一个jiankao so beautiful!
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=30;i>=0;i--){
		int tmp=ans|(1<<i);
		int cnt=0;
		for(int j=0;j<n;j++){
			if((a[j]&tmp)==tmp)
				cnt++;
		}
		if(cnt>=m)
			ans=tmp;
	}
	cout<<ans;
    return 0;
}
