#include<bits/stdc++.h> 
using namespace std;
string w[1001],n[1001];
long long t,v,q,e[1001];
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>e[i]>>w[i];
	} 
	for(int i=0;i<q;i++){
		if(w[i]==w[i+1]){
			v++;
		}
	}
	if(v==q-1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<q;i++){
		t+=e[i];
	}
	cout<<t/2;
	return 0;
	
}
