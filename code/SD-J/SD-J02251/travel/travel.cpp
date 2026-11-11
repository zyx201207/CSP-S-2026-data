#include<bits/stdc++.h>
using namespace std;
const int N=10;
int f[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		f[1]=0;f[2]=0;f[3]=0;f[4]=0;
	}
	else{//同一个车厢 
		f[1]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){//同一排 
			f[2]=1;
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]<='F' && s2[2]<='F' && s1[2]>='D' && s2[2]<='D')){
				f[3]=1;
				if(abs(s1[2]-s2[2])==1){
					f[4]=1;
				} 
			}	
		}
	}
	cout<<f[1]<<f[2]<<f[3]<<f[4];
	return 0;

}
