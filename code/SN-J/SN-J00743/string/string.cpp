//chenzehao xianfulunzhongxue SN-J00743
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[100000005];
	int b[100000005];
	int c[100000005];
	int n=0;
	cin>>n>>endl;
	int num=0;
	int wd;
	int g=0;
	for(int i=1;i<=n;i++){
		cin>>num>>wd>>endl;
		for(int j=g;j<=g+num;j++){
			a[j]=wd;
		}
		g=num+g;
		
	}
	int cnt=g/2;
	for (int i=1;i<=cnt;i++){
		b[i]=a[cnt-i];
	}	
	for (int i=cnt;i<=g;i++){
		c[i]=a[i];
	}
	int k=0;
	for (int i=1;i<=cnt;i++){
		if(b[i]!=c[i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}
