#include<bits/stdc++.h>
using namespace std;
int n,m,maxl=INT_MIN;
long long a[110000],b[110000],l,num,sum[110000];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	b[i]=abs(a[i]-a[i-1]);
}
//for(int i=1;i<=n;i++)
//cout<<b[i]<<" ";
sum[1]=b[1];num=1;
long long mm,ok=1;;
for(int i=2;i<=n;i++)
{
if(sum[i-1]+b[i]<=m){
sum[i]=sum[i-1]+b[i];
//
num++;	
}
else{

	if(maxl<sum[i])
	{
		maxl=sum[i];
		mm=num;
	}
	int j=1;	sum[i]=sum[i-1]+b[i];
	if(sum[i]<0){
		sum[i-1]=0;
		sum[i]=0;
		;
	}
	while(sum[i]>m&&j<=n){
	
		sum[i]-=b[j];
		num--;	
		j++;
	}
	
}
	
}
mm=max(mm,num);
cout<<mm;
return 0;
}
/*
9 4
0 1 2 3 4 5 6 7 8 9
1 1 1 1 1 1 1 1 1 1

5 5
1 2 4 8 9
1 1 2 4 5 

-3 -1 2 2 7
 3  2 3 0 5


0 5
0 9 1 3 5 1 2
1 9 8 2 2 4 1


5 5
1 2 4 8 9

 5 8
-3 -1 2 2 7
*/
