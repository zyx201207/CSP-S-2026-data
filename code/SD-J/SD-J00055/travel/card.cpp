#include<bits/stdc++.h>
using namespace std;
int rd(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c==x){
			f=-1;
			c=getchar();	
		}
	}
while(c>='0'&&c<='9'){
	x=x*10+c-'0';
	c=getchar();
}
return x*f;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out,"w",stdout);
	int n=rd();
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=rd();
		if(x==0){
			ans++;
		}
	}
	
	return 0;
} 
