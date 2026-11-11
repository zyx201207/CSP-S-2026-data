#include<bits/stdc++.h>
using namespace std;
	string c1,s1,c2,s2;
	bool t1,t2,t3,t4;
	int sj1,sj2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1=(c1==c2);
	for(int i=0;i<=1;i++){
		sj1=sj1*10+(s1[i]-'0');
		sj2=sj2*10+(s2[i]-'0');
	}
	t2=(t1&&sj1==sj2);
	sj1=s1[2]-'A'+1;
	sj2=s2[2]-'A'+1;
	t3=(t2&&((sj1<=3&&sj2<=3)||(sj1>=4&&sj2>=4)));
	t4=(t3&&((sj1>=4&&sj2>=4)||(sj1<=3&&sj2<=3&&abs(sj1-sj2)==1)));
	cout<<t1<<t2<<t3<<t4;
	
	
	
	
	
	return 0;
} 
