#include<bits/stdc++.h>
using namespace std;
int q[500050],w[300050];
int j=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(w[a]==0){
			j++;
			w[a]=j;
		}
		else{
			j=w[a];
		}
		q[i]=a;
	}
	for(int i=1;i<=j;i++){
		cout<<q[i];
	}
}
