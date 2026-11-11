#include <bits/stdc++.h>
using namespace std;
int a[500005],t[500005],f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int y=0;
	while(n--){
		int k=0;
		for(int i=1+y;i<=n;i++){
			f[a[i]]++;
			if(f[a[i]]>1){
				k=i;
			}
		}
		for(int i=1+y+k-1;i<=n;i++){
			t[a[i]]++;
		}
		y++;
	}
	for(int i=1;i<m;i++){
		cout<<t[i]<<" ";
	}
	cout<<n;
	return 0;
}
