#include<bits/stdc++.h>
using namespace std;
int a[300005],t[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j;
	cin >> n >> m;
	for(i=1;i<=n;i++){
        cin >> a[i];
	}
	for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            t[a[j]]=i;
        }
	}
	for(i=1;i<=300005;i++){
        if(t[i]>0) cout << t[i] << " ";
	}
	return 0;
}
