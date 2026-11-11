#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
    cin>>n>>m;
    vector<int> a;
    a.resize(n);
    for(int& i:a){
        cin>>i;
    }
    if(m==n){
    	int s=a[0];
        for(int i=1;i<n;i++){
        	s&=a[i];
		}
		cout<<s;
        return 0;
    }
    if(m==n-1){
    	int mx=a[1];
        for(int i=2;i<n;i++){
        	mx&=a[i];
		}
    	for(int i=1;i<n;i++){
    		int s=a[0];
    		for(int j=0;j<n;j++){
    			if(i!=j){
    				s&=a[j];
				}
			}
			mx=max(mx,s);
		}
		cout<<mx;
		return 0;
	} 
	cout<<*max_element(a.begin(),a.end());
	return 0;
}

