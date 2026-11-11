#include<bits/stdc++.h>
using namespace std;
int toi[20];
int tin[10][20];
int w[20][20];
int con[20][20];
int l[20];
int k[10];
int ans[20];
int sta[20][20];
int c,n,m,d,q;
void f(int s){
	for(int i=1;i<=l[s];i++){
		int p=con[s][i];
		if(ans[p]>ans[s]+w[s][p]){
			ans[p]=ans[s]+w[s][p];
			f(p);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>toi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>sta[i][j]>>tin[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int o=j+1;o<=k[i];o++){
				int p1=sta[i][j],u2=sta[i][o];
				w[p1][u2]=tin[i][p1]+tin[i][u2];
				w[u2][p1]=tin[i][p1]+tin[i][u2];
				l[p1]++;
				l[u2]++;
				con[p1][l[p1]]=o;
				con[u2][l[u2]]=j;
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		int a=0;
		a=toi[s]+toi[t];
		for(int i=1;i<=m;i++){
			ans[i]=10000000;
		}
		ans[s]=0;
		f(s);
		cout<<ans[t]+toi[s]+toi[t]<<endl;
	}
	return 0;
} 






