#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m,vi,count=0,temp=0,v_max,v_min,temp_mm;
	vector<int> v,b,res,temp_v;
	
	cin>>n>>m;
	
	for(int qq=0;qq<n;++qq)
	{
		cin>>vi;
		v.push_back(vi);
	}
	
	temp_mm=v[0];
	for(int fm=0;fm<(int)v.size();++fm)
	{
		if (temp_mm<v[fm])
		{
			temp_mm=v[fm];
		}
	} 
	v_max=temp_mm;
	
	temp_mm=v[0];
	for(int fm=0;fm<(int)v.size();++fm)
	{
		if (temp_mm>v[fm])
		{
			temp_mm=v[fm];
		}
	} 
	v_min=temp_mm;
	
	for (int i=v_min;i<=v_max;i++)
	{
		
		temp=0;
		vector<int> b;
		
		for(int j=0;j<(int)v.size();++j)
		{
			if(i-v[j]>=0)
			{
				b.push_back(i-v[j]);
				temp+=1;
			}
		}
		
		count=0;
		
		for(int jj=0;jj<(int)b.size();jj++)
		{
			count+=b[jj];
		}
		if(count<=m)
		{
			res.push_back(count);
			temp_v.push_back(temp);
		}
	}
	
	cout<<temp_v[temp_v.size()-1];
	
	return 0;
}
