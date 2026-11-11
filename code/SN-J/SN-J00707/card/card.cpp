//dujingqi jiandafuzhong SN-J00707
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[50005];
	int cc[50005]={};
	int c1[50005]={};
	for(int i=0; i<n; i++){
		cin>>c[i];
	}
	for(int j=0; j<n; j++){
		for(int x=0; x<n; x++){
			if(c[x]==cc[x]){
				for(int z=0; z<n; z++) cc[z]=0;
			}
			else cc[x]=c[x];
		}
		if(!cc==0){
			for(int y=0; y<n; y++){
				c1[y]++;
			}
		}
	}
	for(int a=0; a<n; a++){
		cout<<c1[n]<<" "<<endl;
	}
	return 0;
}
