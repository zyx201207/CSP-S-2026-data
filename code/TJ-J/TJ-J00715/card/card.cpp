#include<bits/stdc++.h>
using namespace std;

int n,m;
int x[500010],y[500010],z[500010]; 
int ans[300010];
int ly,lz;

int fd(int fl){
	
	for(int i=1;i<=n;i++){
		if(y[i]==fl){
			return i;
		}
	}
	return -1;
	
}

int cl(int st){
	
	
	for(int i=st+1;i<=n;i++){
		y[i]=0;
	}
	
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=n;i++){
		ly=i-1;lz=1;
		
		for(int j=1;j<=i-1;j++){
			y[j]=0;
		}
		for(int j=i;j<=n;j++){
			z[lz]=x[j];
			lz++;
		}
		lz--;
		
		int dy=1;
		
		for(int j=1;j<=lz;j++){
			
			if(fd(z[j])==-1){
				y[dy]=z[j];
				dy++;
			}else{
				
				cl(fd(z[j]));
				dy=fd(z[j])+1;
			}
			
		}
		
		for(int j=1;j<=dy;j++){
			ans[y[j]]++;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		cout << ans[i] << " " ;
	}
	
	
	return 0;
	
}





