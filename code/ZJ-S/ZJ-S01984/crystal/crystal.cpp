#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("cristal.in","w",stdin);
	freopen("cristal.out","r",stdout);
    int n;
    int m;
    int ans=0;
    cin>>n>>m;
    int ct=m;
    vector<int> lst(n);
    for(int i=0;i<n;i++){
    	cin>>lst[i];
	}
    sort(lst.begin(),lst.end());
	for(int i=1;i<n;i++){
		if(ct>0){
			ct=ct-lst[i]+lst[i-1];
			ans=ans+1;
		}
	}	
	cout<<ans;
    return 0;
}
