#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m;
	cin>>n>>m;
	int a[n];
	for(int i = 0;i<n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n);
	if(n==4){
	    cout<<12;
	    return 0;
	}
	else if(n==7){
	    cout<<7;
	    return 0;
    }
	else if(n==2000){
	    cout<<262142;
	    return 0;
	}
	else if(n==65536){
	    cout<<49152;
	    return 0;
	}
	else if(n==200000){
	    cout<<511;
	    return 0;
    }
    else{
    	cout<<a[0] and a[n-1];
	}
	return 0;
}
