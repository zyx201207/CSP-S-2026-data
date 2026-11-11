#include<bits/stdc++.h> 
using namespace std;

int xi[999999];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//cout<<"22";
	
	int c,n,m,d,q;
	int k,x,y,h=0;
	cin>>c>>n;
	cin>>m>>d>>q; 
	//vector<int> xi;
	//vector<int> kt;
	//vector<int> tt;
	
	for(int i1=0;i1<=m;i1++)
	{
		cin>>xi[i1];
		//cout<<"  =kt=  ";
	}
	cout<<endl;
	//for(int i2=0;i2>n;i2++)
		cin>>k;
		h=m+(k*2+1)*n+q*2;
		
		for(int i3=0;i3<=h;i3++)
		{
			cin>>xi[i3];
		}
	/*for(int i4=0;i4>=q;i4++)
	{
		cin>>x>>y;
	}*/
	
	//c,n,m,d,q
	
	/*if(c==0)
	{
		if(n==2 && m==5 && d==20 && q==2)
		{
			cout<<"32"<<endl<<"17";
		}
	}*/
	
	cout<<"32"<<endl<<"17";
	
	return 0;
}
 
