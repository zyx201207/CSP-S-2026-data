//西安理工大学附属中学
//SN-J00843 
//戴琨洋 
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	
	int n,q=0,w=0,tle=0,mid=0,entle=0;
	cin>>n;
	string s[35]=0;
	int num[105];

	for(int i=0;i<n;i++){
		if(i%2==0){
		cin>>num[q];
		q++;	
		}
		if(i%2==1){
		cin>>s[w];
		w++;	
		}
	}
	for(int i=0;i<q;i++){
		tle+=num[i];
	}
	mid=tle%2+tle/2;
    for(int i=0;i<n;i++){
        entle+=num[i];
		if(entle>=mid){
			break;
		}	
	}
	cout<<tle-entle;	
	
	
	
	
	
	
	return 0;
}
