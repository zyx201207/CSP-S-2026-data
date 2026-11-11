#include<bits/stdc++.h>
using namespace std;
int n,m,same;
int a[10011];
bool cmp(int x,int y){
    if(x%2==1){
    	if(y%2==1){
    		return x>y;
		}
		if(y%2==0){
			return 1;
		}
	}else{
		if(y%2==1){
    		return 1;
		}
		if(y%2==0){
			return x>y;
		}
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);   
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+n,a+n+1,cmp);
	int sum=1;
	for(int i=1;i<=m;i++){
		sum=sum+(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
