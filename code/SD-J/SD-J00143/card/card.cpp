#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],ans1[500001],ans2[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			int flag=0;
			for(int k=1;k<j;k++){
				if(b[k]==b[j])flag=1;
				if(flag==1)b[k]=0;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				ans1[b[j]]=1;
				b[j]=0; 
			}
		}
		for(int j=1;j<=m;j++)ans2[j]+=ans1[j],ans1[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans2[i]<<" ";
	return 0;
}//4 3 4
