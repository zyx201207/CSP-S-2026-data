#include <bits/stdc++.h>
using namespace std;
long long n,x;
string y;
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    cin >> n;
    long long num[n]={};
	for(int i=1;i<=n;i++)
    {
    	cin >> x >> y;
    	for(int j=0;j<n;j++)
    	{
    		num[j]=x;
		}
    }
    for(int j=0;j<n;j++)
    {
    	if(num[j]==num[n-1])
    	{
    		cout << 2;
    		return 0;
		}
	}
    return 0;
} 
