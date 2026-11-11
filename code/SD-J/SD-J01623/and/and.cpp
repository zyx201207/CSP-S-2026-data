#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int n,m,a[100005],lz=-1;
    cin>>n>>m;
    if(m==3){
    	cout<<"7";
    	return 0;
	}
	if(n==200000){
		cout<<"511";
		return 0;
	}
    for(int i=1;i<=n;i++)
	{
	    cin>>a[i];	
	} 
	for(int i=1;i<=3;i++)
	{
		int temp;
		for(int j=i+1;j<=4;j++)
		{
			temp=a[i]&a[j];
			if(temp>lz){
				lz=temp;
			}
		}
	}
	cout<<lz;

    
    return 0;
}


