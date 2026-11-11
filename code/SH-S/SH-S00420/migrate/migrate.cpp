#include<bits/stdc++.h>
using namespace std;
const int N=109;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c[N],d[N],e[N][N],ans[N];
	int f=0;
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>c[i]>>d[i];
		for(int j=0;j<c[i];j++)
			cin>>e[j][i];
	}
	for(int i=0;i<b;i++)
		for(int j=0;j<c[i];j++)
			for(int f=0;f<c[i]-j;f++)
				if(e[j+f][i]-e[j][i]+1==2*d[i]&&f<=3&&f>b/2)
					ans[i]++;
	for(int i=0;i<b;i++)
		cout<<ans[i]<<endl;
	return 0;
}
