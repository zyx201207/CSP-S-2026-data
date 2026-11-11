#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,p1,p2;
int a[15],f[15]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//判断是否同车厢，是则继续判断下一层 
		a[1]=1;
		p1=(s1[0]-'0')*10+(s1[1]-'0');//取两人的排号 
		p2=(s2[0]-'0')*10+(s2[1]-'0');
		if(p1==p2){//判断是否同排 
			a[2]=1;
			if(f[s1[2]-'A']==f[s2[2]-'A']){//判断是否同侧  
				a[3]=1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){//判断是否相邻 
					a[4]=1;
				} 
			}
		} 
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	
	return 0;
}

