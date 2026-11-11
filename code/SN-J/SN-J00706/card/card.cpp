//朱毅然 陕西延安中学 SN-J00706
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],ju[500010],t[500010];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	for(int i=1;i<=500009;i++) b[i]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) ju[i]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t[i]=a[i];
		for(int j=1;j<i;j++){
			if(t[j]==t[i]){
				for(int k=j;j<i;k++) ju[k]=0;
			}
		}
		for(int j=1;j<=n;j++)
			if(ju[j]) b[t[j]]++;
		for(int j=1;j<=n;j++) ju[j]=1;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
