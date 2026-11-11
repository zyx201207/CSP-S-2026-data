#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,c1,s2,c2,arr[2],brr[2];
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)
	cout<<"1";
	arr[2]=c1;
	brr[2]=c2;
	if(arr[1]==brr[1])
	cout<<"1";
	else
	cout<<"0";
	if(s1!=s2){
	cout<<"0000";
	}

	return 0;
	
}