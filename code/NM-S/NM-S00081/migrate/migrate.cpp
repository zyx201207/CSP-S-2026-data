#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<int> a;
    for(int i=0;i<5;i++){
        int t;
        cin>>t;
        a.insert(a.begin()+i,t);
    }sort(a.begin(),a.end());
    for(int i=0;i<5;i++){
    	cout<<a[i];
	}
	return true;
}
