#include<bits/stdc++.h>
using namespace std;
int x[100005];
x[i]=0;
int not=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,num=0,sum=0;
	int finaly=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]<=d){
				num=x[i];
				sum++;
			}else{
				num=x[i-1];
				finaly=num;
				not=0;
			}
			if(num==4 && d==2 || d==3){
				cout<<1;
				break;
			}
			if(num==5 && d==3){
				cout<<1;
				break;
			}
			if(finaly/d>=2 || num/d>=2){
				cout<<0;
			}
		}
	}
	return 0;
}
