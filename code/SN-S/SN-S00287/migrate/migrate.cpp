#include <bits/stdc++.h>
using namespace std;
int a[500010];
int mn=10010;
int c,t;
int nm=0;
int number,far;
void tui(int k,int num){
	if (k==1){
		if (mn>num){
			mn=num;
			nm=0;
		}else if (mn==num){
			nm++;
		}
		return ;
	}else if (k<1){
		return ;
	}
	for (int i=1;i<=far;i++){
		tui(k-i,num+1);
	}
}
int main (){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		int zui=0;
		cin>>number>>far;
		for (int j=1;j<=number;j++){
			cin>>a[j];
		}
		for (int j=1;j<=number;j++){
			int mn=10010;
			tui(j,0);
			if (nm==2){
				zui++;
			}
		} 
		for (int j=1;j<=number;j++){
			a[j]=0;
		} 
		cout<<zui+1<<endl;
	}
	
	return 0;
}
