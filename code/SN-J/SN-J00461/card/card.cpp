#include<bits/stdc++.h>
using namespace std;
int a,b;
int x[20005],y[20005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
		y[i]=x[i];
	}
	int m=a,h=0;
	while(m>0)
		for(int h;h<a;h++){
			for(int i=0;i<a;i++){
				for(int j=0;j<i;j++){
					if(x[j]==x[i]){
						for(int z=j;z<h;z++){
							x[z]=0;
						}
					}
				}
			}
		}
		m--;
		h++;
	}
	for(int i=0;i<a;i++){
		if(x[i]>0){
			cout<<x[i]<<" ";
		}
	}
	return 0;
}
