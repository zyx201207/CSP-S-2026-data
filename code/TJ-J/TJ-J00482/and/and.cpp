#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	int max=-10000;
	int m7;
	int ans=0;
	for(int i=0;i<a;i++){		
		cin>>m7;
		if(m7>max){
			max=m7;
		}
	}
	cout<<max;
	return 0;
} 
