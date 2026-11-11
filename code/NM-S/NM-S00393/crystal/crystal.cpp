#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n , m , a[100000];
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    int j=1 , e=0 , v=0;
    sort();
    for(int i=1;i<=n;i++){
		while(j<=i){
			e=a[i]-a[j]+v;
			v=e;
			j++;
		}
		if(e==m){
			cout << e;
			return 0;
		}
	}
		
return 0;
}
