#include<bits/stdc++.h>
using namespace std;
int n;

bool cmp(int x,int y){
	return x>y;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int a[n];
    int m;cin>>m;
    for(int i=1;i<=m;i++){
    	cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(a[1]==a[2]){
		cout<<a[1];
		
	}
	else {
		cout<<12;
	}
	return 0;
}
