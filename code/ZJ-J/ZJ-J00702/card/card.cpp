#include<bits/stdc++.h> 
using namespace std;
int f1[500010],f2[300010],a[500010],c[300010],fi=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		fi=0;
		for(int j=i;j<=n;j++){
			if(!f2[a[j]])f1[++fi]=a[j],f2[a[j]]=fi;
			else{
				for(int k=f2[a[j]]+1;k<=fi;k++)f2[f1[k]]=0;
				fi=f2[a[j]];
			}
		}
		for(int k=1;k<=fi;k++)c[f1[k]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
