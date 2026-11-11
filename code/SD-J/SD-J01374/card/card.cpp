#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005],st[5005],t[3005],top,cnt1,cnt2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=i;j<=n;j++){
				st[++top]=a[j];
				for(int k=1;k<top;k++){		
					if(st[k]==a[j]){
						top=k;
						break;
					}
				}
			}
			for(int j=1;j<=top;j++){
				t[st[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	return 0;
}

