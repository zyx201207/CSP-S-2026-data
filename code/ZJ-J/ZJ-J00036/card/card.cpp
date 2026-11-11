#include<bits/stdc++.h>
using namespace std;
int a[500005],t,b[500005];
map<int,int>cmp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int q = 1;q<=n;q++){
		t=0;
		for(int i = q;i<=n;i++){
			for(int j = 1;j<=t;j++){
				if(a[i]==b[j]){
					t=j-1;
					break;
				}
			}
		    t++;
		    b[t]=a[i];
		}
		for(int j = 1;j<=t;j++){
			cmp[b[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<cmp[i]<<" ";
	}
	return 0;
}
