#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,maxn=0,maxn2=0;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
    	long long x;
    	cin>>x;
    	if  (x>maxn ){
    		maxn=x;
		}
		if  (x<maxn && x>maxn2){
    		maxn2=x;
		}
	}
	if (m==1){
		cout<<maxn;
		return 0;
	}
	else{
		cout<<maxn2;
		return 0;
	}
}
