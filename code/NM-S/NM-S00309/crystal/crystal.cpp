#include<bits/stdc++.h>
using namespace std;
struct gay{ 
	int bh,sl;
	
	};
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   int n,m;
   cin >> n >> m;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int sum=0;
for(int i=1;i<=5000000;i++){
	sum+=i;
	if(sum>=m){
		cout<<i+1;
		break;
		}
	}


   fclose(stdin);
   fclose(stdout);
return 0;
}

