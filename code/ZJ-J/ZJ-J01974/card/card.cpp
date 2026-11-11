#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long awa[100001][2];
		long long l=i;
		for(int j=i;j<=n;j++){
			if(awa[a[j]][0]==1){
				l=max(awa[a[j]][1]+1,l);
				awa[a[j]][1]=j;
			}else{
				awa[a[j]][0]=1;
				awa[a[j]][1]=j;
			}
		}
		for(int j=l;j<=n;j++){
			s[a[j]]+=1;
		}
		for(int j=1;j<=n;j++){
			awa[j][1]=0;
			awa[j][0]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
