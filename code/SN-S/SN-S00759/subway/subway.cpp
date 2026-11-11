#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q; 
int a[500005];
struct qq{
	int aj,ti;
}v[505][100005];
int k[505];
int sx,sy;
int bj[25];
int ans=9e9;
void qqq(int price,int qd,int lx){
	if(qd==sy){
		ans=min(ans,price+a[qd]);
	}
	cout<<price<<" ";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(v[i][j].aj==qd){
				for(int y=1;y<=k[i];y++){
					if(bj[y]==0){
						if(lx==i){
							bj[qd]=1;
							qqq(price+v[i][j].ti,y,i);
						}else {
							bj[qd]=1;
							qqq(price+v[i][y].ti,y,i);
						}
					}
				}
				break;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		k[i]=x;
		for(int j=1;j<=x;j++){
			cin>>v[i][j].aj>>v[i][j].ti;
		}	
	}
	while(q--){
		cin>>sx>>sy;
		ans=9e9;
		for(int i=1;i<=25;i++){
			bj[i]=0;
		}
		bj[sx]=1;
		for(int i=1;i<=n;i++){
			int f=9;
			for(int j=1;j<=k[i];j++){
				if(v[i][j].aj==sx){
					f=0;
					qqq(a[sx],sx,i);
					break;
				}
			}
			if(f==0){
				break;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
