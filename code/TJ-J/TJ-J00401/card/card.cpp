#include<bits/stdc++.h>
//asd
using namespace std;
int a[500005],b[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int asd=1;asd<=n;asd++){
		for(int i=0;i<=n;i++){
			b[i]=0;
		}
		int hou=asd;
		for(int i=asd;i<=n;i++){
			for(int j=asd;j<=i;j++){
				if(a[i]==b[j]&& b[j]!=0){ 
					for(int y=j;y<=n;y++){
						b[y]=0;
					}
					hou=j;break;
				}
			}
			b[hou]=a[i];hou++;
			
		}
		for(int i=1;i<hou;i++){
			++t[b[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	//tj-j00401
	//Wei Da De Yang Yang 
	return 0;
} 
