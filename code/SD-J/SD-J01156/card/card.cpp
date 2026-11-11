#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],t2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				for(int k=t[a[j]];k<=j;k++){
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				t2[a[j]]++;
				t[a[j]]=0;
			}
		} 
	} 
	for(int i=1;i<=m;i++){
		cout<<t2[i]<<" ";
	}
	return 0;
} 
