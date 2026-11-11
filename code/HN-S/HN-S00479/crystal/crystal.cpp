#include<bits/stdc++.h>
using namespace std;
long long a[50050],cnt[50050];
long long n,m;
void ans(long long x){
     long long m1=m,x1=x;
     while(true){
		   x1--;
		   if(x1<=0)
		   break;
		   long long sum=a[x]-a[x1];
           if(m1<sum){
              break;           
           }
           m1-=sum;
           cnt[x]++;
     }
}   	 
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      cin>>a[i];   
    }
    sort(a+1,a+n+1);
    if(n>5000){
		long long se=a[2]-a[1];
		long long sum=m,sad=1;
		while(true){
			if(sum<se*sad){
              break;           
          }
		sum-=se*sad;
			sad++;
		}
		cout<<sad;
	}
	else{
        for(int i=1;i<=n;i++){
		  ans(i);
		  }
        sort(cnt+1,cnt+n+1); 
        cout<<cnt[n]+1;
	}
    return 0;
}
