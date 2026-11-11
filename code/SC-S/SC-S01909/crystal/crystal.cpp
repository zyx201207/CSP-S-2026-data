#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N+10];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	int num=0;
	int x=0;
	if(n>=2)
	   	for(int i=1; i<=m; i++){
	   		if(a[i]>a[i]+1){
	   			swap(a[i],a[i+1]);
	   			a[i]+1;
	   		    m-1;
			   }
	   		    if(a[i]=a[i+1]){
				   a[i]==0;
				   a[i+1]+1;
				   m-1;
				   num++;
				 			    		   	  
			   }
			   if(m==0&&a[i]<a[i+1])
			   break;
	    }
	cout<<num-1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    return 0;
} 