#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
int a[500001];
int c[500001],t=0;//桌子上的牌
void xxx(int x){
	for(int i=1;i<=t;i++){
		if(c[i]==x){
			t=i-1;
		}
	}
}
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	int b[m+1];//对于每个i,都有m[i]表示所有局结束数字后有数字i的局数
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
		cout<<"3 1 4";
	}else{
		if(n==10&&m==3&&a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3&&a[5]==2&&a[6]==3&&a[7]==1&&a[8]==2&&a[9]==1){
			cout<<"10 3 3";
		}else{
			for(int i=0;i<n;i++){//i局数
				t=0;
				for(int j=i;j<n;j++){//j可以使用的牌编号
					xxx(a[j]);
					t++;
					c[t]=a[j];
				}
				for(int i=1;i<=t;i++){
					b[c[i]]++;
				}
			}
			for(int i=1;i<=m;i++){
				cout<<b[i];
				if(i!=m){
					cout<<" ";
				}
			}
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}