#include <bits/stdc++.h> 
using namespace std;
int main{

freopen("train.in","r",stdin);
freopen("train.out","w",stdout);
int n,m; 
cin>>n>>m;
int n[i];
int minn;
cin>>minn;
for(int i=1;i<=n;i++)
{ if(n[i]+1==n[i+1])
  {n[i]=minn;
  	n[i]+=n[i-1];
  	m++;
  else if(n[i+1]==n[i+n]){
    {n[i+1]+n[i+n];
       m++;
		}	
  	
  }
}
  while(n>0)	
 {minn+n[i-1]=n[i];
 	n[i]==minn;
 	m++; 
 	
}
  if(n[i]+1!=n[i+1])break;
  


}
cout<<m;                                                                                                                                                                                                              
return 0; 
}
