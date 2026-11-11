//SN-S00450 韩翊杨 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	//frein(crystal,in,w);
	//freout(crystal,out,r);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	
	int w=0;
	int r=-1;
	while(m>0){
		int e=a[w]-a[w+1];
		
		int d=r*e;
	
	
		a[w]=a[w+1];
		
		m=m-d;
	
		w++;
		r--;
	}
	for(int i=0;i<w;i++)
	{
		a[i]=a[w];
	}

	
	
	
	int t=a[0];
	int num=0;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			num++;	
		}
	}
	cout<<num;
	
	
	
	return 0;
}

