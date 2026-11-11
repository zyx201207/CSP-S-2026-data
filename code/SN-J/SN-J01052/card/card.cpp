#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500005],lst[300005],T[300005]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
//	for(int i=1;i<=m;i++){
//		cout<<lst[i]<<" ";
//	}
//	cout<<endl;
	for(int F=1;F<=n;F++){
		for(int i=1;i<=m;i++){
			int k=0;
			for(int j=F;j<=n;j++){
				if(a[j]==i){
					k=j;
					break;
				}
			}
			if(F>lst[i]){
				continue;
			}
			bool flg=1;
			for(int j=F;j<=k-1;j++){
				if(lst[a[j]]>=lst[i]){
					flg=0;
				}
			}
			if(flg){
//				if(i==2){
//					cout<<F<<endl;
//				}
				T[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<T[i]<<" ";
	}
	return 0;
}
//无力回天
