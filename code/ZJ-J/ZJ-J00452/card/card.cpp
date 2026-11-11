#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001],ci[200001],p[200001],jia[200001];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);

	for(int i=1;i<=200001;i++)b[i]=0,ci[i]=0,p[i]=-1,jia[i]=0;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=1;
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[a[i]]==0)p[cnt]=a[i],b[a[i]]=cnt,cnt++;
			else {
				int linshi=b[a[i]];
				for(int i=b[a[i]];i<cnt;i++)b[p[i]]=0,p[i]=-1;
				cnt=linshi;
				p[cnt]=a[i];
				b[a[i]]=cnt;
				}
		}
		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
			cout<<endl;
		int flag=1;
		while(p[flag]!=-1){
			if(jia[p[flag]]==0)
				ci[p[flag]]++,jia[p[flag]]=1;
			flag++;
		}
		for(int k=1;k<=200001;k++)b[k]=0,p[k]=-1,jia[k]=0;
		cnt=1;
	}
	for(int i=1;i<=m;i++)cout<<ci[i]<<' ';
	return 0;
}