#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen(travel.in,"r","in");
	freopen(travel.out,"w","out");
	string c1,s1,c2,s2;
	long long a[5]={0,0,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=2;i++){
		if(c1[0]!=c2[0]){
			cout<<"0000"<<endl;
		}
		a[1]=1;
	}
	if(a[1]==1 and s1[0]==s2[0] and s1[1]==s2[1]) a[2]=1;
	if(a[2]==1 and (s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D')) a[3]=1;
    if(a[3]==1 and (s1[2]+1==s2[2] or s1[2]-1==s2[2])) a[4]=1;
    cout<<a[1]<<a[2]<<a[3]<<a[4];

}
