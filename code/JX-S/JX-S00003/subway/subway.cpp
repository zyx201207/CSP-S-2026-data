#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500005],a[505][505],t[505][505],x[100005],y[100005];
long long sum=LONG_LONG_MAX;
void swap(int x,int y,int track,long long total,long long step,int ti,int t2){
	if(x==y){
		sum = min(sum,total-t[track][ti]+w[y]);
		return;
	}
	if(total>sum||step>1000000){return;}
	for(int i=0; i<n; i++){
		for(int j=1; j<=a[i][0]; j++){
			if(a[i][j]==x){
				if(i==track){
					if(j+1<=a[i][0]&&ti>t2)swap(a[i][j+1],y,i,total,step+1,j+1,j);
					if(j-1>0&&ti<t2)swap(a[i][j-1],y,i,total,step+1,j-1,j);
				}else{
					if(track==500005){
						if(j+1<=a[i][0]&&ti>t2){swap(a[i][j+1],y,i,total+w[i]+t[i][j+1]+t[i][j],step+1,j+1,j);}
						if(j-1>0&&ti<t2){swap(a[i][j-1],y,i,total+w[i]+t[i][j-1]+t[i][j],step+1,j-1,j);}
					}else{
						if(j+1<=a[i][0]&&ti>t2){swap(a[i][j+1],y,i,total+t[track][ti]+t[i][j+1],step+1,j+1,j);}
						if(j-1>0&&ti<t2){swap(a[i][j-1],y,i,total+t[track][ti]+t[i][j-1],step+1,j-1,j);}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0; i<m; i++)cin >> w[i];
	for(int i=0; i<n; i++){
		cin >> a[i][0];
		for(int j=1; j<=a[i][0]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=0; i<q; i++)cin >> x[i] >> y[i];
	for(int i=0; i<q; i++){
		sum=LONG_LONG_MAX;
		swap(x[i],y[i],500005,0,0,500005,0);
		cout << sum << endl;
	}
}
/*
0 2 5 20 2                        
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
FAILED
OHNOOOOOOOO

*/
