#include<bits/stdc++.h>
using namespace std;
struct SUBWAY{
	int To[25];
	int Stp[25];
	int len;
} a[500010]; 
int c,n,m,d,q;
int w[500010];
int dfs(int stop,int cost,int to,int times){
	if(times>10) return 1000000;
	int Min=2147483647;
		for(int i=0;i<n;i++){
			bool f=false;
			for(int j=0;j<a[i].len;j++){
				if(a[i].To[j]==stop) f=true;
				if(a[i].To[j]==to)	return a[i].Stp[j]; 
			} 
		}
		for(int i=0;i<n;i++){
			bool f=false;
			for(int j=0;j<a[i].len;j++){
				if(a[i].To[j]==stop) f=true; 
			}
			if(f=true){
				for(int j=0;j<a[i].len;j++){
					if(a[i].To[j]==stop) continue; 
					Min=min(Min,dfs(a[i].To[j],cost+a[i].Stp[j],to,times+1));
				}
			}
		}
	return Min;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	//cout<<1;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		a[i].len=k;
		for(int j=0;j<k;j++){
			cin>>a[i].To[j]>>a[i].Stp[j];
		}
	}
	//cout<<2;
	int Min=2147483647;
	for(int aa=0;aa<q;aa++){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i].len;j++){
				if(a[i].To[j]==x) Min=min(Min,dfs(x,a[i].Stp[i],y,0));
			} 
		}
		cout<<Min<<endl; 
	}
	return 0;
}
