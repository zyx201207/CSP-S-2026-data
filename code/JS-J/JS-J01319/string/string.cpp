#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	vector<long long>a;
	vector<char>c;
	for(int i=0;i<n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		if(c.empty()||c[c.size()-1]!=y){
			a.push_back(x);
			c.push_back(y);
		}
		else{
			a[a.size()-1]+=x;
		}
	}
	long long l=0;
	for(int i=0,j=0;i!=a.size()-1-j;){
		if(c[c.size()-1-j]==c[i]){
			if(a[a.size()-1-j]>a[i])
			{
				a[a.size()-1-j]-=a[i];
				i++;
			}
			else{
				a[i]-=a[a.size()-1-j];
				j++;
			}
		}
		else{
			if(a[a.size()-1-j]>a[i])
			{
				a[a.size()-1-j]-=a[i];
				l+=a[i];
				i++;
			}
			else{
				a[i]-=a[a.size()-1-j];
				l+=a[a.size()-1-j];
				j++;
			}
		}
	}
	cout<<l;
	return 0;
}
