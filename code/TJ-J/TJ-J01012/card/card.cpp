#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T;
int a[N];
int card[N],top;
int tong[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(card[k]==a[j]){
					top=k-1;
					break;
				}
			} 
			card[++top]=a[j];
	 }
		for(int j=1;j<=top;j++){
			tong[card[j]]++;
		}
	}
	for(int i=1;i<=T;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
} 

