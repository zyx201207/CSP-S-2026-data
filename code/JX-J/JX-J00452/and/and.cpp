#include<bits/stdc++.h>
using namespace std;
int a[200000+5];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int q,w,b;
    cin>>q>>w;
    for(int i=0;i<q;i++){
		cin>>a[i];
		if(a[i]>b){b=a[i];}
	}
	if(w==1)cout<<b;
	else{cout<<a[q-1];}
    return 0;
}
