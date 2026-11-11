#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N];
bool f[M];//标记 当前是否有重 
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
    if(m==1){
    	cout<<n;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	if(a[i]==a[i+1]){
    		continue;
		}
		else{
			cout<<i;
		}
	}
    
	return 0;
} 


















