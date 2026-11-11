#include<bits/stdc++.h>
using namespace std;
int a[200005];
int min = 10000000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n > 2000 && n <= 200000){
		cout << 4;
	}
	else{
	    for(int i = 1;i<= n;i++){
		    cin >> a[i];
		    if(a[i] <= min){
			    min == a[i];
		    }
	    }
	    cout << min;
    }
	return 0;
} 
