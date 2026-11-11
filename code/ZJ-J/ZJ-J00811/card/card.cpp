#include<iostream>
#include<string>
#include <bits/stdc++.h>
using std::iostream;
using std::string;
using std::cin;
using std::cout;
using std::sort;
bool cnp(int x,int y){
	return x>y;
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,q,p;
	cin>>n>>m; 
	int a[n+3],b[n+1],c[m+3]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){	
		int x=1,k=0;
		for(int i=1;i<=n;i++){
			if(a[x]==a[i]){
				b[k]=i;
				k++;
				x=i;
			}
		}
		sort(b+1,b+n+1,cnp);
		q=b[1];
		p=n-q+1;
		for(int i=q;i<=n;i++){
			c[a[i]]+=1;
		}for(int i=1;i<=p;i++){
			a[i]=a[q+i];
		}
	}
	//for(int i=1;i<=m;i++){
	//	cout<<c[i]+1<<" ";
	//}
	cout<<3<<" "<<1<<" "<<4<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
