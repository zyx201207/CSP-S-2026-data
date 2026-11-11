#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],t[500005],ans[300005],index=-1;
int check(int begin,int end,int value){
	if(index==-1) return -1;
	while(begin<=end){
		if(t[begin]==value) return begin;
		begin++;
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int tmp=check(0,index,a[j]);
			if(tmp==-1){
				t[++index]=a[j];
			}else{
				index=tmp;
			}
		}
		for(int j=0;j<=index;j++){
			ans[t[j]]++;
		}
		index=-1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
