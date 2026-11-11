#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],t2[300005],last[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		t[a[i]]++;
		for(int j = i+1;j<=n;j++){
			t[a[j]]++;
			if(t[a[j]]!=1){
				for(int k = last[a[j]];k<j;k++){
					t[k]--;
				}
			}else{
				last[a[j]]=j;
			}
		}
		for(int i = 1;i<=m;i++){
			if(t[a[i]]){
				t2[a[i]]++;
				t[a[i]]=0;
			}
		}
	}
	for(int i = 1;i<=m;i++) cout<<t2[i]<<" ";
	return 0;
}
