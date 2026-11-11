#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],zx[500050];
bool bo[500050];
long long v[500050],point1=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(bo,0,sizeof(bo));
		memset(zx,0,sizeof(zx));				
		for(int j=1;j<=n;j++){
			if(bo[j]==0){
			v[point1]=a[j];
			point1++;
			zx[a[j]]=point1;
			bo[j]=1;				
			}else{
				int g=0,g1=zx[a[j]];
				for(int q=g1;q<=point1;q++){
					g++;
					v[q]=0;
					bo[q]=0;
					zx[a[j]]=0;
				}
				v[point1]=a[j];
				point1++;
				zx[a[j]]=point1;
				bo[j]=1;
			}}
		for(int j=1;j<=point1;j++){
				b[v[point1]]++;
			}			
		}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
