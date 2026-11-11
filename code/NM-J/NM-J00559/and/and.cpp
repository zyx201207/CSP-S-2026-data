#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ma=-1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ma=max(a[i],ma);
	}
	int ans=0;
	if(m==1)cout<<ma;
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=a[i]&a[j];
			}
		}
		cout<<ans;
	}
    return 0;
}

