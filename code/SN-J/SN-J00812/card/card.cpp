//刘雨辰 SN-J00812 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5*10001],b[5*10001],c=0,d=0,e[5*10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	d=n;
	for(int i=0;i<n;i++){
		d--;
		for(int q=0;q<d;q++){
			b[i]=a[i];
			for(int j=0;j<c;j++){
				if(b[i]=b[j]){
					for(int k=j;k>0;k++){
						b[j]=0;
					}
				}
			
			}
		}
		for(int g=0;g<n;g++){
			if(b[i]!=0){
				a[b[i]]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
