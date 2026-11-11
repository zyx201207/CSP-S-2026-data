#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int d1=d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			
		}
		int snum=0;
		for(int x=0;x<n-1;x++){
			for(int y=x+1;y<n;y++){
				int siz=y-x;
				bool f[siz];
				for(int j=0;j<siz;j++){
					f[i]=false;
				}
				int now=x;
				int num1=0;
				int num2=0;
				int f2=false;
				while(now!=y){
					if(d1>=(a[now+1]-a[now])){
						d1-=(a[now+1]-a[now]);
						now++;
					}
					else{
					    num1++;
					    f[now]=true;
					    d1=d;
					} 
				}
				while(now!=x){
					if(d1>=(a[now]-a[now-1])){
						d1-=(a[now]-a[now-1]);
						now--;
					}
					else {
					    num2++;
					    if(f[now]==false) f2=true;
					    d1=d;
					}
				}
				if(num1==num2&&f2==true) snum++;
			}
		}
		cout<<snum<<endl;
	}
	return 0;
} 
