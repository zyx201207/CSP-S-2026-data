#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","w"stdin);
	//freopen("and.out","r"stdout);
	int n,m,i;
	cin>>n>>m;
	int a[i],b[i],c[i],d[i];
	int x,y,e,f;
	int max;
	for(int i=1;i<=m;i++){
		if (a + b == x){
			max++;
		}
		if(a + c == y){
			max++;
		}
		if(b + c ==e){
			max++;
		}
		if(c + d ==f){
			max++;
		}
	}
	cout<<max;
	return 0;
}	
		
		
	
