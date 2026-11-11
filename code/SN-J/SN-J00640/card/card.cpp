// 李思齐 陕西省西安爱知中学 SN-J00640 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[80000],b,n,m,bik[5500],bis[5000],bid[105000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){
		for(int i=1;i<=n;i++){
			bid[a[i]]=1;
		}
		int oft=1;
		for(int i=1;i<=105000;i++){
			if(bid[i]){
				cout<<oft<<" ";
				oft++;
			}
		}
	}
	else if(n<=500){
		for(int h=1;h<=n;h++){
			memset(bid,0,sizeof(bid));
			memset(bik,0,sizeof(bik));
			for(int i=h;i<=n;i++){
				bik[i]=a[i];
				for(int j=i-1;j>=1;j--){
					if(bik[j]==bik[i]){
						for(int k=j;k<i;k++){
							bik[k]=0;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
					if(bik[i]){
						bid[bik[i]]=1;
					}
				}
			for(int i=1;i<=m;i++){
				bis[i]+=bid[i];
			}
		}
		 for(int i=1;i<=m;i++){
			cout<<bis[i]<<" ";
		}
	}
	return 0;
}
/*
4 3
1 2 1 3*/
