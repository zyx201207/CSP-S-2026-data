#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout );
	int c1[2],s1[3],c2[2],s2[3],a[4];
	cin>>c1[2]>>s1[3]>>c2[2]>>s2[3];
	if(c1[1]=c2[1]){
	int a[1]={1};
	}else{
	int a[1]={0};
	}
	if(c1[2]=c2[2]){
	int a[2]={1};
	}else{
	int a[2]={0};
	}
	if(s1[2]=s2[2]){
	int a[3]={1};
	}else{
	int a[3]={0};
	}
	if(s1[3]=s2[3]){
	int a[4]={1};
	}else{
	int a[4]={0};
	}
	cout<<a[1]+a[2]+a[3]+a[4];
	return 0;
} 
