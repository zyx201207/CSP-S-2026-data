#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int n,m;
int a[500005]={},c[300005]={};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int bigfor=1;bigfor<=n;bigfor++){
		int dt[500005]={};
		int t=0;
		for(int i=bigfor;i<=n;i++){
			bool flag=1,f0t;
			for(int j=0;j<t;j++){
				if(dt[j]==a[i]){
					flag=0;
					f0t=j;
					break;
				}
			}
			if(flag){
				dt[t++]=a[i];
			}
			else{
				t=f0t+1;
			}
		}
		for(int i=0;i<t;i++){
			c[dt[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
