#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,n1,m1,duo,lms=0,num=0,sum=0,aum=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>n1>>m1;
		for(int j=0;j<=n1;j++){
			cin>>duo;
			while(duo>=i){
				for(int h=0;h<=duo;h++){
					num++;
				}
			}
			sum++;
		}
		aum++;
	}
	lms=sum+num+aum;
	cout<<lms;
}
