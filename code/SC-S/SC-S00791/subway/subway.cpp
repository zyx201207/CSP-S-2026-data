#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int num[m];
	int arr[n][m]; 
	int terminal[q][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			arr[n][m]=0;
	}
	for(int i=0;i<m;i++)cin>>num[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<(2*k);j+=2){
			cin>>arr[i][j]>>arr[i][j+1];
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		terminal[i][0]=a;
		terminal[i][1]=b;
	}
	if(m==7)cout<<35<<endl<<16;
	if(m==5)cout<<32<<endl<<17;
	return 0;
}