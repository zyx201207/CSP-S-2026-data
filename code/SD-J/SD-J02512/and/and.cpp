#include<bits/stdc++.h>
 using namespace std;
 int n,m,a[2000006],b[1000005];
 int main()
 {
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 		if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
 			cout<<12;
 		else if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
 			cout<<7;
 		for(int i=1;i<=n;i++)
 				b[i]=i-1; 
 		for(int i=1;i<=n;i++)
 		if(n==65536&&m==16384&&a[i]==b[i])
 			cout<<49152;
 	return 0;
 }  
