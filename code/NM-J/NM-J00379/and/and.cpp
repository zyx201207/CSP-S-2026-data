#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num=0;
    long long a[10005];
    long long ans=0;
    cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			if(a[num] and a[i+1]>=ans){
				ans=a[num] and a[i+1];
			}
		}
		num++;
	}
	cout<<ans;
	return 0;
}
