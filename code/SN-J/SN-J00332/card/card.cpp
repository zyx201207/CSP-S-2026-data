#include <bits/stdc++.h>
using namespace std; 
struct stu{
	int num=0;
	int ci=1;
	int zuoyong=0;
	int beginto=0;
	int endto=0;
}z[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>z[i].num;
		z[i].zuoyong=i;
		for (int j=i-1;j>=1;j--){
			if (z[i].num==z[j].num){
				z[i].ci++;
				if (z[i].ci%2==0 && z[j].beginto==0){
					z[i].endto=j;
					z[j].beginto=i;
				}
			}
		}
		if (z[i].endto>0){
			for (int j=i-1;j>z[i].endto;j--){
				if (z[j].endto>0){
					for (int k=j-1;k>z[j].endto;k--){
						z[k].zuoyong+=z[z[i].endto].zuoyong;
					}
				}
				z[j].zuoyong-=z[z[i].endto].zuoyong;
			}
			
		}
	}
	
//	for (int i=1;i<=n;i++){
//		cout<<z[i].num<<" "<<z[i].zuoyong<<" "<<z[i].endto<<" "<<z[i].beginto<<" "<<z[i].ci<<" "<<"next";
//	}
//	cout<<endl;
	for (int i=1;i<=m;i++){
		for (int j=n;j>=1;j--){
			if (z[j].num==i){
				cout<<z[j].zuoyong<<" ";
				break;
			}
		}
	}
	return 0;
}
