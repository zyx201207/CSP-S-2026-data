#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int w1,w2,w3,w4,wm;
	cin>>w1>>w2>>w3>>w4>>wm;
	int t11,t12,t22,t23;
	cin>>t11,t12,t22,t23;
	cout<<w1+t11+(t12+t22)+t23+w3<<endl;
	cout<<w1+t11+t12+w2;
	return 0;
}