#include<bits/stdc++.h>
using namespace std;
int num=0,aum=0,sum=0,j,i;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		int m;
		cin>>m;
		for(int j=0;j<=m;j++){
			num++;
			while(j<i){
				cout<<num;
				sum++;
				
			}
		}
		aum++;
	}
	cout<<sum<<num<<aum;
	return 0;
	
} 
