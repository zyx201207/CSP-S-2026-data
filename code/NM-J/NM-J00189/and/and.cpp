#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long s[N];
int f(int idx,int num){
	if(idx==n){
		return 0;
	}
	if(num<0){
		return 0;
	}

	int p1=f(idx+1,num-1)^s[idx];
	int p2=f(idx+1,num);
	return max(p1,p2);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>s[i];
	}
	cout<<f(0,m);
    return 0;
}
