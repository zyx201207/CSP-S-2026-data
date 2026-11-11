#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],xx[100010],st[200010];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]<a[i-1])flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			cout << i << " ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int cnt=1;
			for(int j=i;j<=n;j++){
				for(int k=1;k<cnt;k++){
					if(st[k]==a[j]){
						cnt=k;
						break;
					}
				}
				st[cnt]=a[j];
				cnt++;
			}
			for(int j=1;j<cnt;j++){
				xx[st[j]]++;
			}
			memset(st,0,sizeof(st));
		}
	}
	for(int i=1;i<=m;i++){
		cout << xx[i] << " ";
	}
	
	
	return 0;
} 
