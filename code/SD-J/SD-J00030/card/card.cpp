#include<bits/stdc++.h>
using namespace std;
struct node{
	int dat;
	int nex=0;
	int pre;
};
int a[500010];
int t[300010];
int tt[300010];
node c[500010];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(tt,0,sizeof tt);
	for(int l=1;l<=n;l++){
		memset(t,-1,sizeof t);
		for(int i=1;i<=n;i++){
			c[i].nex=0;
			c[i].dat=0;
			c[i].pre=0;
		}
		
		int pre=0,p=1,ans=0;
		c[0].dat=-1;
		c[0].nex=p;
		for(int i=l;i<=n;i++){
//			cout<<i<<" ";
			if(t[a[i]]==-1){
				t[a[i]]=p;
				c[p].dat=a[i];
				c[pre].nex=p;
				c[p].pre=pre;
				pre=p;
				p++;
			}else if(t[a[i]]!=-1){
				c[c[t[a[i]]].pre].nex=p;
				t[a[i]]=p;
				c[p].dat=a[i];
				c[p].pre=c[t[a[i]]].pre;
				pre=p;
				p++;
			}
			if(i==n){
				c[p-1].nex=-2;
			}
		}
//		cout<<'\n';
		int bl=0;
		while(1){
//			cout<<bl<<" ";
			if(c[bl].dat==-1){
				bl=c[bl].nex;
				if(bl==0||bl==-2){
					break;
				}
				continue;
			}
			if(bl==-2){
				break;
			}
			tt[c[bl].dat]++;
			bl=c[bl].nex;
			if(bl==0){
				break;
			}
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<tt[i]<<" ";
	}
	
	return 0;
} 
