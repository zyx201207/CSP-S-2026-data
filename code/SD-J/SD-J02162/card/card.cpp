#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cnt[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i]){
			flag=0;
		}
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt[a[i]]=i;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
		int last[100001]={0};
		for(int j=i;j<=n;j++){
			if(last[a[j]]!=0){
				for(int k=last[a[j]];k<=j;k++){
					last[a[k]]=0;
				}
			}
			last[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(last[i]!=0){
				cnt[i]+=1;
			}
		}
	}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

