#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int a[N],n,m,maxs,x;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	maxs=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]>m&&a[i]-a[i-1]<-m){
	    cout<<maxs;
		}
	    if(a[i]-a[i-1]<=m&&a[i]-a[i-1]>0){
			m--;
			a[i-1]++;
		    if(m==0){
		    
			    cout<<maxs;
		}
		    if(m!=0&&a[i]-a[i-1]>m){
	           cout<<maxs;
	    }
    }      
		if(a[i-1]==a[i]){
			maxs++;
	} 
        if(a[i]-a[i-1]<0&&a[i]-a[i-1]>=-m){
        	m--;
        	a[i]++;
			if(-m==0){
				cout<<maxs;	
			} 
			if(m!=0&&a[i]-a[i-1]<-m){
	           cout<<maxs;
	        }
	    }  
    }
        cout<<maxs;
	return 0;
}









//一年没碰电脑全忘了(!~!) 
//让我过一个测试点也行啊 
