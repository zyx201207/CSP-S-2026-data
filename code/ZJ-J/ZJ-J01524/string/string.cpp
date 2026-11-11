#include<bits/stdc++.h>
using namespace std;
long long ans,n;
struct node{
	long long a;
	char c;
}b[234567];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&b[i].a);
		b[i].c=getchar();
		while(b[i].c>'z'||b[i].c<'a')
		b[i].c=getchar();
	}
	long long i=1,j=n;
	ans=0;
	while(i!=j){
		if(b[i].a<b[j].a){
			if(b[i].c!=b[j].c)ans+=b[i].a;
			b[j].a-=b[i].a;
			i++;
		}
		else{
			if(b[i].c!=b[j].c)ans+=b[j].a;
			b[i].a-=b[j].a;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
