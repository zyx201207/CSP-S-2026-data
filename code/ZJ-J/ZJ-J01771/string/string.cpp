#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1,ans;
struct L{
	long long Len;
	char op;
}vec[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int Len;
		char opt;
		cin>>Len>>opt;
		vec[i]={Len,opt};
	}
	long long Head=1,Headsum=vec[1].Len,Tail=n,Tailsum=vec[n].Len;
	while(Head<Tail){
		long long Get=min(Headsum,Tailsum);
		Headsum-=Get,Tailsum-=Get;
		if(vec[Head].op!=vec[Tail].op)ans+=Get;
		if(Headsum==0)Head++,Headsum=vec[Head].Len;
		else Tail--,Tailsum=vec[Tail].Len;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
