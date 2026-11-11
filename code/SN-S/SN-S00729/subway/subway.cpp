#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q,x,y,k,tion[50],sub[50][50],r[50][50];
	cin>>c>>n>>m>>d>>q;
	int ans[q];
	for(int w=1;w<=m;w++){
		cin>>tion[w];
	}
	for(int i=1;i<=n;i++){
		  cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>sub[i][j];
		}
	}
	for(int f=1;f<=q;f++){
		for(int e=1;e<=2;e++){
			cin>>r[f][e];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*k;j++){
			if(sub[i][j]==r[i][j]){
				ans[i]+=tion[j];
				if(i=1){
					ans[i]+=sub[i][j];
					break;
					
				}
			}
		}
	}
	
	for(int i=1,j=1;j<=2*k;j++){
		for(int m=2,n=1;n<=2*k;n++){
		if(sub[i][j]==sub[m][n]){
			ans[i]+=sub[i][j]+sub[m][n];
			break;
		}
		}
	}
	cout<<ans;
	return 0;
}
