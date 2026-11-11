#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,t[100009]={};
    cin>>a>>b;
    for(int i=1;i<=a;i++){
    	cin>>t[i];
	}
	sort(t+1,t+1+a,cmp);
	cout<<t[b];
    return 0;
}
