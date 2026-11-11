#include<bits/stdc++.h> 

using namespace std;
long long c,n,m,d,q,k,ans,x,y,ai;
struct zhan{
	int t;
	int aj[500];
	int vis;
	long long go;
};
queue q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long w[m+5];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	zhan a[m+5];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;i++){
			cin>>ai;
			a[ai].aj[n]=i;
			cin>>a[ai].t;
		}	
	}
	for(int r=0;r<q;r++){
		cin>>x>>y;
		ans+=w[x]>>w[y];
		a[x].go=0;
		a[x].vis=1;
		q.push(a[x]);
		while(q.empty()){
			for(int i=0;i<m;i++){
				if(a[i].aj==)
			}
			q.top()
			q.pop()
		}
		
		
	}
	
	return 0; 
}
