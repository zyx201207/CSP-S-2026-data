#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
long long M[N],maxn=-1;
void sovl1(){
	for(int i=1;i<=n;i++){
		maxn=max(maxn,M[i]);
	}
}
void sovl2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		maxn=max(maxn,M[i]&M[j]);
	}	
}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>M[i];
	}
    if(n<=2000 && m==1){
    	sovl1();
    	cout<<maxn;
	}
	if(n<=2000 && m==2){
		sovl2();
		cout<<maxn;
	}
    return 0;
}


