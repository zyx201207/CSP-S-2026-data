#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[300005],k[300005][3]={};
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		if(k[a[i]][0]==0){
			k[a[i]][0]=1;
			k[a[i]][1]=i;
		}else{
			int l=k[a[i]][1];
			for(int j=i;j<l;j++){
				k[a[j]][0]=0;
				k[a[j]][1]=0;
			}
			k[a[i]][0]=1;
			k[a[i]][1]=i;
		}
		for(int j=1;j<=m;j++){
			s[j]+=k[j][0];
			
		}
	}
	for(int j=1;j<=m;j++){
		cout<<s[j]<<' ';
	}
	return 0;
}
