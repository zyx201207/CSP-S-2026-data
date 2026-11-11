#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[500005],d[500005];
int idx;
void c(int m){
	for(int i=0;i<idx;i++){
		if(d[i]==m){
			idx=i;
			return;
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		idx=0;
		for(int j=i;j<n;j++){
			c(a[j]);
			d[idx]=a[j];
			idx++;
		}
		for(int j=0;j<idx;j++){
			cnt[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
