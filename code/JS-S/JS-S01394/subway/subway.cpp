#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1005]={};
int k[505]={};
struct node{
	bool aa=0;
	int jg;
};
long long minn=INT_MAX;
node s[505][1005]={};
bool vis[505][505]={};
void ddd(int x,int y,long long ans){
	//cout<<"aaa"<<endl;
	if(x==y){
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<n;i++){
		if(s[i][x].aa==1){
			for(int j=0;j<m;j++){
				if(s[i][j].aa==1){
					if(vis[i][j]==1){
						return;
					}
					else{
						vis[i][j]=1;
						//cout<<j<<endl;
						ddd(j,y,ans+s[i][x].jg+s[i][j].jg);
					}
				}
			}
		}
	}
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=0;i<n;i++){
	cin>>a[i];
}
for(int i=0;i<n;i++){
	cin>>k[i];
	for(int j=0;j<k[i];j++){
		int la;
		cin>>la;
		cin>>s[i][la].jg;
		s[i][la].aa=1;
	}
}
for(int i=0;i<q;i++){
	int x,y;
	cin>>x>>y;
	if(7<=c&&c<=11){
		ddd(x,y,a[x-1]+a[y-1]);
		cout<<minn;
		minn=INT_MAX;
		for(int i1=0;i1<505;i1++){
			for(int i2=0;i2<505;i2++){
				vis[i1][i2]=0;
		}
		}
	}
}

return 0;
}
