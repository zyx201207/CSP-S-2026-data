#include<bits/stdc++.h>
using namespace std;
long long n,a;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	string h;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			h+=c;
		}
	}
	
	for(int i=0;i<=h.length()/2;i++){
		if(h[i]!=h[h.length()-1-i]){
			sum++;
		}
	}
	cout<<sum;
	
	
	return 0;
	
}
