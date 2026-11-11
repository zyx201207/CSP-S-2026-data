#include <bits/stdc++.h>
using namespace std;
int n,m,pz[300010],yy[300010],sx[300010],cs[300010],ll;//pz是牌组，sx是桌面顺序，yy是桌面已经有的牌，cs是这种牌出现的局数次数
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pz[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			sx[j]=pz[j+i-1];
			yy[sx[j]]+=1;
			if(yy[sx[j]]>1){
				for(int q=1;q<j;q++){
					if(sx[j]==sx[q]){
						ll=q;
					}
				}
				for(int p=ll;p<j;p++){
					yy[sx[p]]-=1;
					sx[p]=0;
				}
				
			}
		}
		for(int z=1;z<=m;z++){
			cs[z]+=yy[z];
			yy[z]=0;
		}
		for(int y=0;y<=n;y++){
			sx[y]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<cs[i]<<" ";
	}
	return 0;
	
}
