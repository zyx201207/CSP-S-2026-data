#include<bits/stdc++.h>
using namespace std;
long long int c,t,k,f,l,i,j,m[100000],ao[100000][100000],ju[10000],ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(i=1;i<=t;i++)
	{
		cin>>m[i]>>ju[i];
		for(j=1;j<=m[i];j++)
		{
			cin>>ao[i][j];
		}
    }
	for(i=1;i<=t;i++)
	{

		for(f=k;f<=m[i];f++)
		{
			for(l=1;l<=m[i];l++)
			{	
			if(ao[i][l]-ao[i][f]==3&&ju[i]==2)
			ans++;			
			}
		}
		if(ans-2>=0)
		cout<<ans-2<<endl;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
