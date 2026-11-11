#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c[100005],d[100005],h[100005]={0};
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			d[j]=c[j];
		}
		for(int j=i;j<=a;j++){
			for(int k=i;k<j;k++){
				if(d[k]==d[j]){
					for(int p=k;p<j;p++){
						d[p]=0;
					}
				}
			}
		}
		for(int j=i;j<=a;j++){
			h[d[j]]++;
		}
	}
	for(int i=1;i<=b;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
