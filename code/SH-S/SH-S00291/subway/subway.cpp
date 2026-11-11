#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;

unsigned long t[501][500502]={0};

struct node{
	int w=0,id;
	bool flag;
}sta[500001],lin[501];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	for(int i=1;i<501;i++) {
		lin[i].flag=true;
		lin[i].id=i;
	}
	queue<node> pro;
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++){
		scanf("%d",&sta[i].w);
		sta[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&d,&c);
			t[i][d]=c;
		}
	}
	
	for(int j=1;j<=n;j++){
		bool went[500502]={0};
		pro.push(lin[j]);
		int ori=j;
		while(!pro.empty()){
			node u=pro.front();
			pro.pop();
			if(u.flag){
				for(int i=1;i<=m;i++){
					if(t[u.id][i]!=0){
						unsigned long cal = t[u.id][i]+t[ori][500001+u.id];
						if(!went[i]) {
							t[ori][i]=cal;
							pro.push(sta[i]);
							went[i]=true;
						}
						else if(cal<t[ori][i]){
							t[ori][i]=cal;
							if(!went[i]) {
								pro.push(sta[i]);
								went[i]=true;
							}
						}
						
					}
				}
			}
			else {
				for(int i=1;i<=n;i++){
					if(t[i][u.id]!=0){
						unsigned long cal = t[i][u.id]+t[ori][u.id];
						if(!went[500001+i]) {
							t[ori][500001+i]=cal;
							pro.push(lin[i]);
							went[500001+i]=true;
						}
						else if(cal<t[ori][500001+i]){
							t[ori][500001+i]=cal;
							if(!went[500001+i]) {
								pro.push(lin[i]);	
								went[500001+i]=true;
							}
							
						}
					}
				}
			}
		}
	}
	
	int x,y;
	for(int i=0;i<q;i++){
		unsigned long ma=4200000000;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			if(t[i][x]+t[i][y]<ma) ma=t[i][x]+t[i][y];
		}
		printf("%d\n",ma+sta[x].w+sta[y].w);
	}
	
	return 0;
} 
