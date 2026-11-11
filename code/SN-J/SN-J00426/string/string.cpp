#include<bits/stdc++.h>
using namespace std;
long long n,ans,le=1,ri;
struct str{
	long long num;
	char sn;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ri=n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].sn;
	}
	while(le<=ri){
		long long minn=min(s[le].num,s[ri].num);
		if(s[le].sn!=s[ri].sn) ans+=minn;
		s[le].num-=minn;
		s[ri].num-=minn;
		//cout<<s[le].num<<" "<<s[le].sn<<"  "<<s[ri].num<<" "<<s[ri].sn<<'\n';
		if(s[le].num<=0) le++;
		if(s[ri].num<=0) ri--;
	}
	cout<<ans;
	return 0;
}
