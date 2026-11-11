#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in""r")
    freopen("travel.out""w")
    long long 'c1','s1','c2','s2';
    cin>>'c1'>>'s1'>>'c2'>>"s2";
    for(int i=2;i<=15;i++){
        if('c1'=='s1'){
            cout<<1;
            for(int j=1;j<=18;j++){
		if('c2'=='s2'){
                    cout<<1;
		}else{
                    cout<<0;
		}
            }
	}else{
            cout<<0;
	}
    }
    return 0;
}
