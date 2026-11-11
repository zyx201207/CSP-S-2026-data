#include <bits/stdc++.h>
using namespace std;
//const int N=1e9+5;
long long n,l,x=0,mid,sum=0;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>l;
		cin>>a;
		for(int i=x;i<x+l;i++){
			s[i]=a;
		}
		x+=l;		
	}
		if(x/2==(x+1)/2){
			mid=x/2;
			//cout<<mid;
			for(int i=0;i<=mid;i++){
				if(s[i]!=s[x-i-1]) sum++;
			}	
		} 
		if(x/2!=(x+1)/2){
			mid=(x+1)/2;
			//cout<<mid;
			for(int i=0;i<mid;i++){
				if(s[i]!=s[x-i-1]) sum++;
			}	
		} 
	cout<<sum;
	return 0;
}
