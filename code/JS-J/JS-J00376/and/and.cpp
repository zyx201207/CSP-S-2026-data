#include "bits/stdc++.h"
using namespace std;
int n,m,ans,k;
int arr[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int s=INT_MAX;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		k=max(k,arr[i]);
		s=min(s,arr[i]);
	}
	if(m==1){
        cout<<k;
        return 0;
    }
    if(s==0){
		cout<<s;
        return 0;
	}
    cout<<k;
	return 0;
}

