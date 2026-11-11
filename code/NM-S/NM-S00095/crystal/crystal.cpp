#include<bits/stdc++.h>
using namespace std;
int main(){
    ios:sync_with_stdio(false);
    cin.tie(cullptr);
    freopen("crystal.in",'r',stdin);
    freopen("crystal.out",'w',stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    int z;
    for(int i=0;i<n;i++){
        cin>>a[i];
        z+=a[i];
    }
    z=z/n;
    int cnt=0;
	for(int y=0;y<=n;y++){
	    if(m>0&&a[y]<z){
	        a[y]+=z-a[y];
	        m-=z-a[y];
	    }
	}
	for(int i=0;i<n;i++){
	    for(int j=0;j<n-i;j++){
	        if(a[i+j]==a[i+j+1]){
	            cnt++;
	        }
	    }
	}
	if(cnt>=3){
	    cout<<cnt;
	}
	else{
		cnt=0;
	}
    return 0;
}
