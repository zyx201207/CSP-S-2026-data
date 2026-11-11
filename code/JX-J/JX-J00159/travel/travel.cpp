#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,ans=0,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){  
		ans+=1;
		if(c[0]==d[0]&&c[1]==d[1]){  
			ans+=1;
			if(c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C'){
				ans+=1;
				if(c[2]+1==d[2]||c[2]-1==d[2])  ans+=1;
				}
			else if(c[2]>='D'&&c[2]<='F'&&d[2]>='D'&&d[2]<='F'){
				ans+=2;}
			}
			}
	int s[4]{0,0,0,0};
	for(int i=0;i<ans;i++)  s[i]=1;
	for(int i=0;i<=3;i++)  cout<<s[i];
	return 0;
}
