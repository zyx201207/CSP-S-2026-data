#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdout);
	freopen ("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=i;
		b[a[t]]++;
		for(int j=i+1;j<=n;j++){
			//cout<<a[t]<<" "<<a[j];
			if(a[t]==a[j]){
				for(int k=j-1;k>=i;k--){
					b[a[k]]-=1;
				}
				t=j;
			}
			b[a[j]]++;
		}
		/*for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
		}cout<<endl;*/
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}