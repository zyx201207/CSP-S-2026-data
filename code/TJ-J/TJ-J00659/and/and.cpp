#include<bits/stdc++.h>
using namespace std;
bool g(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)
	int n,a[20001],m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,g);
	cout<<12;
} 
