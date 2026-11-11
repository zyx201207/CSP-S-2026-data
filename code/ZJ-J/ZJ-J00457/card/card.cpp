#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],flag,cn[300005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cn[j]=0;
		for (int j=i;j<=n;j++) a[j]=t[j];
		for (int j=n;j>i;j--){
			flag=j;
			for (int k=i;k<j;k++){
				if (t[k]==t[j]){
					flag=k;
					break;
				} 
			}
			for (int k=flag;k<j;k++) a[k]=-1;
		}
		for (int j=i;j<=n;j++){
			if (a[j]) cn[a[j]]=1;
		}
		for (int j=1;j<=m;j++){
			if (cn[j]) cnt[j]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
