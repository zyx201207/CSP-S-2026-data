#include <bits/stdc++.h>
using namespace std;
int a[200010];
int x,y,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>x>>y;
	for (int i=1;i<=x;i++){
		cin>>a[i];
		b=a[1];
		if(a[i]>b){
			b=a[i];
		}
		
	}
	cout<<b;
	//sort(a[1],a[5]);
	//for (int i=1;i<=x;i++){
	//	cout<<a[i];
	//}
	//cout<<a+b;
	//ceil floor sort sprt pow 
	return 0;
} 
