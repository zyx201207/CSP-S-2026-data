#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600000]={};
int math(long long lin,long long left,long long right){
    if(left==right-1||left==right) return left;
    else if(a[(left+right)/2]>lin){
    	return math(lin,left,(left+right)/2);
	}
    else if(a[(left+right)/2]==lin){
    	return math(lin,(left+right)/2,right);
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    preopen("crystal.in","r",stdin);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long t=(n+1)/2;
    t=math(a[t],t,n);
    long long stay=a[t];
    long long ans=0;
    while(t>0){
        if(stay-a[t]>m) break;
        m=m-stay+a[t];
        ans++;
        t--;
    }
    cout<<ans;
    preopen("crystal.out","w",stdout);
    return 0;
}
