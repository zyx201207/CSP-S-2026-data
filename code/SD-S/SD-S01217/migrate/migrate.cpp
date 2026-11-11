#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],ans,u[N];
vector<int>now;
bool B=1,b=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
    	ans=0;
    	b=0;
    	B=0;
    	now.clear();
    	int g=0;
    	scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
    	scanf("%d",&x[i]);
    	u[i]=x[i];
    	if(i==1)continue;
    	else if(i==2)g=x[i]=x[i-1];
    	else if(x[i]-x[i-1]!=g)B=1;
	}
	for(int i=1;i<=n;i++){
		if(u[i]-d<=u[1]&&u[i]+d>=u[n]){
		b=1;
		now.push_back(i);
	}
}
	if(B==0){
		int c=d/g;
		for(int i=1;i<=n;i++){
		if(i+2*c-1<=n)ans++;
		else break;
	}
	printf("%d\n",ans);
}
else if (b==1){
		if(now.size()>2){cout<<0;continue;}
		int j=now[0];
	for(int i=1;i<=n;i++)
{if(i==j)continue;
auto p=upper_bound(u+1,u+1+n,u[i]+d);
int U=p-1-u;
if((U-1>i)&&(U-1==j||U==j)){
	p=upper_bound(u+1,u+1+n,u[U-1]+d);
	int O=p-1-u;
	p=lower_bound(u+1,u+1+n,u[O]-d);
	O=p-u;
	if(U-O==1&&O>i)ans++;
}
}
printf("%d\n",ans);
}
else cout<<0<<"\n";
}
	return 0;
}

