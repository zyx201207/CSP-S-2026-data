#include<bits/stdc++.h>
using namespace std;
long long n[541888],fn[541888];//fn[i]-fn[j]=n[j]+...+n[i-1]
long long f(int i,int a){return n[i-1]*(i-a)-(fn[i]-fn[a]);}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a,maxn=1;
    //int ii=-114514,jj=-114514;
    long long b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
    	cin>>n[i];
    }
    sort(n,n+a);
    for(int i=1;i<=a;i++) fn[i]=n[i-1]+fn[i-1];
    for(int i=1;i<=a;i++){
    	int l=0,mid=(i-1)/2,r=i-1;
    	while(mid!=l){
    	    //cout<<l<<' '<<mid<<' '<<r<<' '<<f(i,mid)<<endl;
    	    if(f(i,mid)>b){l=mid;}
    	    else{maxn=max(maxn,i-mid);r=mid;}
    	    mid=(l+r)/2;
    	}
    	if(f(i,l)<=b) maxn=max(maxn,i-l);
    	//cout<<i<<' '<<l<<' '<<mid<<' '<<r<<' '<<f(i,l)<<endl;
    	//for(int j=i-1;j>=0;j--){
    	    //if(n[i-1]*(i-j)-(fn[i]-fn[j])>b) break;//now use n[i-1] to choose,check n[i-1]*(i-1-j)-(n[j]+...+n[i-2])<=b,if ok,length is i-j 
    	    //maxn=max(maxn,i-j);
    	    //if(i-j>maxn){maxn=i-j;ii=i;jj=j;}
    	//}
    }
    cout<<maxn;
    //cout<<' '<<ii<<' '<<jj<<'\n';
    //for(int i=0;i<a;i++) cout<<n[i]<<' ';
    //cout<<endl<<n[ii-1]*(ii-jj)-(fn[ii]-fn[jj])<<' '<<b<<endl;
    //for(int i=0;i<100;i++) cout<<fn[i]<<' ';
    return 0;
}
//compile 35 times,run 46 times
