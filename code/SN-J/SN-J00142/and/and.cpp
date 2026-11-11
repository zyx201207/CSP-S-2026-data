#include<bits/stdc++.h>
using namespace std;

int n,m,maxm=0;
int a[200005],ai=1;
int x;
bool tf=true;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>x;
		for(int j=0;j<ai;j++){
			if(x==a[j]){
				tf=false;
				break;
			}
		}
		if(tf){
			a[ai]=x;
			ai++;
		}
	}
	sort(a,a+ai);
	cout<<a[ai/2];	
	
	return 0;
} 
