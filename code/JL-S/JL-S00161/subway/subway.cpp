#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int a[n];
	int b[n][2][m];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int x=0;x<a[i];x++){
			cin>>b[i][0][x]>>b[i][1][x];
		}
	}
	int Q[2][q];
	for(int x=0;x<q;x++){
		for(int y=0;y<2;y++){
			cin>>Q[y][x];
		}
	}
	int sum=0;
	for(int l=0;l<q;l++){
		sum=0;
		sum+=w[Q[0][l]];
		sum+=w[Q[1][l]];
		int x1,x2;
			for(int i=0;i<n;i++){
				for(int x=0;x<a[i];x++){
					if(b[i][0][x]==Q[0][l]){
						sum+=b[i][1][x];
						x1=i;
					}
					else if(b[i][0][x]==Q[1][l]){
						sum+=b[i][1][x];
						x2=i;
					}
				}
				if(x1!=x2){
					for(int i=0;i<a[x1];i++){
						for(int x=0;x<a[x2];x++){
							if(b[x1][0][i]==b[x2][0][x]){
								sum+=b[x1][1][i];
								sum+=b[x2][1][i];
							}
						}
					}
				}}
		cout<<sum<<endl;
	}
	
	freopen("subway.in.txt","r",stdin);
	freopen("subway.out.txt","w",stdout);
}
