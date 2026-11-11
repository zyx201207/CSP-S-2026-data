#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
bool cmp[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int q=i;q<=j;q++){
				if(a[q]==a[j])flag=1;
			}
			if(flag){
				memset(cmp,0,sizeof(cmp));
				k=1;
			}
			cmp[k]=1;
			k++;
		}
		for(int j=i;j<=n;j++){
			if(cmp[i])b[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
