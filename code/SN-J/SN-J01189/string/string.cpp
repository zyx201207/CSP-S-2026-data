#include <bits/stdc++.h>
using namespace std;

int main(){
//  freopen("string.in,"r",stdin);
//  freopen("string.out"

    int n;
    long long s;  
    long long a[100005];
    char b[100005];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=n;i++){
		s += a[i];
	}
	if(s%2==0){
		for(int i=1;i<=n;i++){
		    if(b[i] != b[n-i+1]){
		    	s += min(a[i],a[n-i+1]);
		    	a[i] -= a[n-i+1];
		    	if(a[i] <= 0){
		    		break;
				}
			}
		}
	}
    cout << a - b;
    return 0;
} 
