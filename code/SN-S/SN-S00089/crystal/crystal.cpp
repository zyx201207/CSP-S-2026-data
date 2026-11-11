#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0,t=1,x=0;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			x+=a[i+1]-a[i];
			if(x<=m){
			    while(a[i]==a[i+1]){
				    a[i]++;
				    cnt++;
			    }
			    t++;
		    }
		}
		else if(a[i]==a[i+1]){
			t++;
		}
	}
	cout<<t;
	return 0;
}
