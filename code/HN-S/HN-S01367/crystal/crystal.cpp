#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500011],mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int mm=m,j,k;
		for(j=i-1,k=i+1;(j>0 || k<=n) && mm>=0;){
			if(j<=0 && k<=n &&  mm>=a[k]-a[i])
				mm-=a[k]-a[i],k++; 
			else if(k>n && j>0 && mm>=a[i]-a[j])
				mm-=a[i]-a[j],j--;
			else if(j>0 && k<=n){
				if(a[i]-a[j]<=a[k]-a[i] && mm>=a[i]-a[j])
					mm-=a[i]-a[j],j--;
				else if(a[i]-a[j]>a[k]-a[i] && mm>=a[k]-a[i])
					mm-=a[k]-a[i],k++; 
				else break;
			}
			else break;
//			cout<<"("<<j<<","<<k<<"):"<<mm<<endl; 
		}
//		cout<<"("<<j<<","<<k<<"):"<<k-j-1<<endl; 
		mx=max(mx,k-j-1); 
	}
	cout<<mx; 
	return 0;
}
/*
5 5
1 2 4 8 9
6 3
1 -1 12 3 54 23
*/ 
