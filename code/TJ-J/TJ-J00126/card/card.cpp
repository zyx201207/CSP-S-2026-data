#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x[500010]={0},ans=0;
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++){
		    int f=0;
		    for(int k=1;k<=ans;k++){
				if(a[j]==x[k]){
					f=1;
					ans=k;
					break;		
				}
			}
			if(f==0){
				ans++;
				x[ans]=a[j];
			}
		}
		for(int j=1;j<=ans;j++){
			s[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
