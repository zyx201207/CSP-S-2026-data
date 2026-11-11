#include<bits/stdc++.h>
using namespace std;
long long num[500000];
int main(){
    ifstream cin("crystal.in");
    ofstream cout("crystal.out"); 
    long long n,m,maxn=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    for(int i=0;i<n;i++){
    	long long c1=1,k=m;
    	for(int j=i-1;j>=0;--j){
    		long long  mn=num[i]-num[j];
    		if(k>=mn){
    			k-=mn;
    			c1++;
			}
			else
				break;
		}
		if(c1>maxn){
			maxn=c1;
		}
	}  
    cout<<maxn<<endl;
}
