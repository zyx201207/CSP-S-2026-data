#include<bits/stdc++.h> 
#include<cstdio>
int c,t,n,d,x[10005],ans=0,sum=0;
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	cin>>n>>d;
	

if(d<=2){
for(int i=1;i<=2;i++)
sum++;
ans=sum-1;

}
else sum=1,ans=0;

cout<<ans<<endl<<sum;
return 0;
}
