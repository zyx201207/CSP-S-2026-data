#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,cnt[M],a[N],lst[M],v[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(lst,0,sizeof lst);
		int pos=1;
		for(int j=i;j<=n;j++){
			if(lst[a[j]] != 0){
				for(int k=lst[a[j]]+1;k<j;k++) if(lst[a[k]] == k) lst[a[k]]=0;
				pos=lst[a[j]]; 
			} else lst[a[j]] = pos;
			v[pos++]=a[j];
		}
		for(int j=1;j<pos;j++) {
			cnt[v[j]] ++;
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i]<<' ';
	return 0;
}
