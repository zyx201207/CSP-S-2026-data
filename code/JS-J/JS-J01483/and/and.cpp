#include<bits/stdc++.h>
using namespace std;
int n[233333];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,maxn=-1;
    cin>>a>>b;
    for(int i=0;i<a;i++) cin>>n[i];
    sort(n,n+a);
    if(a<=20){
    	for(int i=0;i<(1<<a);i++){
    	    int t=0x3fffffff,t2=0;
    	    for(int j=0;j<a;j++){
    	    	if(i&(1<<j)) t&=n[j],t2++;
    	    }
    	    if(t2==b) maxn=max(maxn,t);
    	}
    }
    else if(b==1) maxn=n[a-1];
    else if(b==a){
    	maxn=0x3fffffff;
    	for(int i=0;i<a;i++) maxn&=n[i];
    }
    else if(a<=5000 && b==2){
    	for(int i=0;i<a;i++){
    	    for(int j=i+1;j<a;j++){
    	    	maxn=max(maxn,n[i]&n[j]);
    	    }
    	}
    }
    else if(b==a-1){
    	int fn[233333]={},bn[233333]={};
    	fn[0]=n[0];
    	bn[a-1]=n[a-1];
    	for(int i=1,i2=a-2;i<a;i++,i2--){
    	    fn[i]=fn[i-1]&n[i];
    	    bn[i2]=bn[i2+1]&n[i2];
    	}
    	maxn=bn[1];
    	for(int i=1;i<a-1;i++) maxn=max(maxn,fn[i-1]&bn[i+1]);
    	maxn=max(maxn,fn[a-2]);
    }
    else{
    	maxn=0x3fffffff;
    	for(int i=1;i<=b;i++) maxn&=n[a-i];
    }
    cout<<maxn;
    return 0;
}
