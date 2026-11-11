#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[500010],b[500010],s=0;
void go(int x,int y,int t){
	if(x==y){
		b[t]++;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			go(i,y,t+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=1;k<=n;k++){
					b[k]=0;
				}
				go(i,j,0);
				for(int k=1;k<=n;k++){
					if(b[k]!=0){
						if(b[k]==2){
							s++;
						}else{
							break;
						}
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
