#include<bits/stdc++.h>
using namespace std;
int a[500001];
int table[500001];
int size=0;
bool flag=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			if(table[j]==a[j]){
			    flag=true;
			}
			else{
		        table[j]=a[j];
		        size++;
		    }
		}
    }
	for(int i=1;i<=size;i++){
		if(i!=1){
			cout<<" ";
		}
		cout<<table[i];
	}
	return 0;
}
