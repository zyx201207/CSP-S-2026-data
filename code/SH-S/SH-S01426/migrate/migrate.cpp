#include<bits/stdc++.h>
using namespace std;
const int max=2000005;
void act(){
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    int lt=lower_bound(a+1,a+n+1,1)-a;
    int rt=upper_bound(a+1,a+n+1,1)-a;
    cout<<lt<<endl<<rt+1;
	return 0;
} 
