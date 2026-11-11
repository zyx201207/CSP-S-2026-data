#include<bits/stdc++.h>
using namespace std;
struct obj{
	int x;
	char a;
}g[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].x>>g[i].a;
		sum+=g[i].x;
	} 
	int i=1,j=sum,s1=1,s2=n;
	int k1=g[s1].x,k2=g[s2].x,i1=k1=g[s1].x,i2=g[s2].x;
	char x=g[s1].a,y=g[s2].a;
	while(i<j){
		int q=min(k1,k2);
		if(x!=y){			
			cnt+=q;	
		} 
		i+=q;
		j-=q;
		if(i>i1) x=g[++s1].a,k1=g[s1].x,i1+=k1;
		if(i>i2) y=g[--s2].a,k2=g[s2].x,i2+=k2;
	}
	cout<<cnt;
	return 0;	
}
