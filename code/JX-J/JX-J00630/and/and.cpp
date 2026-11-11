#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)
	int n,m,mx;
	int a[100010],y=-1999999;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
    for(int i=1;i<+n;i++){
         for(int j=1;j<=n;j++){
            if(a[i]^a[j]>y){
               y=a[i]^a[j];
            }
         }
    }
   cout<<y;
    return 0;
}
