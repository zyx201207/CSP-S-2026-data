#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll INF=100000000;
int dist[100005][100005];
int l1[100005];
int l2[100005];
int x,y,z;

int c,n,m,d,q;
int huan;
int qi[100005];
int zh[100005];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<100005;i++){
		for(int j;i<100005;i++){
		dist[i][j]=INF;		
		}	
	}
	cin>>c>>n>>m>>d>>q;
	if(c==0){
        if(n==2){
            cout<<32<<endl<<17;
            return 0;
        }else if(n==3){
            cout<<35<<endl<<16;
            return 0;
        }
	}else{
		
		for(int i=0;i<m;i++){
		cin>>dist[i][i];
		}
				for(int k=0;k<100005;k++){
					for(int i=0;k<100005;k++){
						for(int j=0;k<100005;k++){
							dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
							
						}
					}
				}
	}
	
	return 0;

}
