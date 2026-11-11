#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],ans[500005];
int main(){
	fropen("card.in","r",stdin);
	fropen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				for(int k=t[a[j]];k<=j;k++){
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}