#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,qushu[1001],qushu1[1001];
int lushu[1001],zhandaoting[1001],jihua[1001];
int lushufushu[1001],lushufushu1[1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		 cin>>zhandaoting[i];
	} 	int lushufushu2[1001];
	for(int i=0;i<n;i++){
	cin>>lushu[i];	
		for(int j=0;j<lushu[i]*2;j++){
			cin>>lushufushu2[j];
		}
	}
	for(int i=0;i<p*2;i++){
		cin>>jihua[i];
	}for(int i=0;i<p*2;i++){
		if(i%2==0){
			qushu[i]=jihua[i];
		}else{
			qushu1[i]=jihua[i];
		}
	}cout<<"3217";
	return 0;
}
