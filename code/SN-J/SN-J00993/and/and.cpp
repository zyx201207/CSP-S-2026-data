#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int m,n;
int bigg[N];
bool cant[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>bigg[i];
	}
	sort(bigg+1,bigg+m+1,cmp);
	if(n==1){
		cout<<bigg[1]<<endl;
		return 0;
	}
	if(bigg[1]==0){
		cout<<bigg[1]<<endl;
		return 0;
	}
	int k=0,y=bigg[1];
	while(k<=n){
		int p=2;
		if(cant[p])	p++;
		y=y&bigg[++p];
		k++;		
		if(y==0){
				cant[p]=true;
				k=0,p=1;
				continue;
			}
	}
	cout<<y<<endl;
	return 0;
}
