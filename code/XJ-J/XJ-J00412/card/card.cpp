#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++){
		cin>>b[i]; 
	}
	int q=0;
	for(int s=0;s<n;s++){
		for(int i=0;i<n;i++){
			int z;
			for(int j=0;j<m;j++){
				z=j;
				if(a[j]==i){
					for(int l=j;l<m;l++){
						a[l]=0;
						q-=1;
					}
					break;
				}
			}
			a[z+1]=b[i];
			q+=1;
		}
		if(a.find[1]){
			a+=1;
		}
		if(a.find[2]){
			b+=1;
		}
		if(a.find[3]){
			c+=1;
		}
	}
	cout<<a<<' '<<b<<' '<<c;
	return 0;
}
