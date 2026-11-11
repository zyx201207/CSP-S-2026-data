#include<bits/stdc++.h>
using namespace std;


int cmp(int x,int y){
	if(x>y){return 1;}
	if(x<y){return 0;}
}

int n,m;
int a[1005];
int b[3005];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int k=0;k<n*(n-1);k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				b[k]=a[i]&a[j];
			}
		}
	}
	
	sort(b,b+n*(n-1)+1,cmp);
	
	cout<<b[0];
	
return 0;
}
