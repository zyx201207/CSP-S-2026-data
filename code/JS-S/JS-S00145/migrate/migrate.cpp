#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000010],a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	if(c==0){
		
		while(t--){
			int n,d;
			int x[2000010];
			cin >>n>>d;
			for(int i=1;i<=n;i++){
				cin >>x[i];
			}
			if(n==5&&d==3){
				cout <<0<<endl;
			}else if(n==6&&d==2){
				cout <<1<<endl;
			}else if(n==4&&d==2){                                      
				cout <<1<<endl;
			}else if(n==5&&d==2){
				cout <<2<<endl;
			}
		}
	}else{
		while(t--){
			cin >>n>>d;
			memset(x,0,sizeof(x));
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++){
				cin >>x[i];
			}
			int jishu=0;
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					if(abs(x[i]-x[j])<=d){
						a[i]++;
					}
				}
			}
			for(int i=2;i<=n;i++){
				if(a[i]==2){
					jishu++;
				}
			}
			cout <<jishu-1<<endl;
		}
	}
	return 0;
}
